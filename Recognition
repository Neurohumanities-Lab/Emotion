# Set the duration to stream data (5 seconds in this example)
duration = 10
# Set the sampling rate and channel(s) you want to stream
sampling_rate = 128
channels = list(range(9))  # Streaming data from channels 0 to 7
# Initialize the board
# Create BrainFlowInputParams object and set the parameters
params = BrainFlowInputParams()
params.serial_port = 'COM8'  # Replace with the actual serial port of OpenBCI Cyton board
board = BoardShim(0, params)
board.prepare_session()

arduino = serial.Serial(port='COM9', baudrate=115200, timeout=.1)
def write_read(x,y,z):
    arduino.write(bytes(str(x), 'utf-8'))
    time.sleep(0.05)
    arduino.write(bytes(str(y), 'utf-8'))
    time.sleep(0.05)
    arduino.write(bytes(str(z), 'utf-8'))
    time.sleep(0.05)

count = 0
repetitions = 0

    
while iteraciones < 2000:

    # Create empty lists to store the streamed data for each channel
    channel_data = [[] for _ in channels]

    # Start the streaming
    board.start_stream()

    # Get the start time
    start_time = time.time()

    # Loop until the specified duration is reached
    while time.time() - start_time < duration:
        # Fetch the latest available samples
        samples = board.get_current_board_data(sampling_rate)

        # Append the samples to the corresponding channel's data list
        for i, channel in enumerate(channels):
            channel_data[i].extend(samples[channel])

        # Sleep for a small interval to avoid high CPU usage
        time.sleep(0.001)

    # Stop the streaming
    board.stop_stream()

    # Create a dictionary with channel names as keys and data as values
    data_dict = {f'Channel_{channel}': channel_data[i] for i, channel in enumerate(channels)}

    # Create a DataFrame from the data dictionary
    df = pd.DataFrame(data_dict)

    row_all_zeros = (df == 0).all(axis=1)
    df2 = df[~row_all_zeros]
    df3 = df2.drop(df.columns[0], axis=1)
    df4 = df3[['Channel_1', 'Channel_2', 'Channel_3', 'Channel_4', 'Channel_5', 'Channel_6', 'Channel_7', 'Channel_8']].copy()

    lowcut = 4  # Lower cutoff frequency in Hz
    highcut = 45  # Upper cutoff frequency in Hz
    fs = 128  # Sampling rate in Hz

    # Apply the bandpass filter to each column
    filtered_df = df4.apply(lambda col: butter_bandpass_filter(col, lowcut, highcut, fs))

    average_reference = filtered_df.mean(axis=1)
    df_average_reference = filtered_df.sub(average_reference, axis=0)

    # Create an empty DataFrame to store the PSD results
    psd_df = pd.DataFrame()

    # Iterate over each column in your DataFrame
    for column in df_average_reference.columns:
        # Compute the PSD for the column data and frequency bands
        psd_bands = compute_psd_bands(df_average_reference[column].values, fs=128)
    
        # Add the PSD values to the DataFrame
        psd_df = psd_df.append(psd_bands, ignore_index=True)

    df_t = psd_df.transpose()
    df_t.columns = ['Fp1', 'Fp2', 'C3', 'C4', 'P7', 'P8', 'O1', 'O2']

    df_t = df_t.reset_index()

    # Use the melt function to reshape the DataFrame
    melted_df = pd.melt(df_t, id_vars='index', var_name='channel', value_name='value')

    # Convert channel numbers to strings
    melted_df['channel'] = melted_df['channel'].astype(str)

    # Create a new 'channel_band' column by combining 'channel' and 'index' columns
    melted_df['channel_band'] = melted_df['channel'] + '_' + melted_df['index']

    # Pivot the DataFrame to get the desired format
    new_df = melted_df.pivot(index='index', columns='channel_band', values='value')

    series = new_df.stack()

    # Convert the Series back to a DataFrame with a single row
    filter_df = pd.DataFrame(series)

    valo =filter_df[0]
    valores = valo.reset_index(drop=True)
    df_modelo = pd.DataFrame(valores).transpose()

    df_modelo.columns = ['C3_Alpha', 'C4_Alpha', 'Fp1_Alpha','Fp2_Alpha','O1_Alpha','O2_Alpha','P7_Alpha','P8_Alpha',
                     'C3_Beta', 'C4_Beta', 'Fp1_Beta','Fp2_Beta','O1_Beta','O2_Beta','P7_Beta','P8_Beta',
                     'C3_Delta', 'C4_Delta', 'Fp1_Delta','Fp2_Delta','O1_Delta','O2_Delta','P7_Delta','P8_Delta',
                     'C3_Gamma', 'C4_Gamma', 'Fp1_Gamma','Fp2_Gamma','O1_Gamma','O2_Gamma','P7_Gamma','P8_Gamma',
                     'C3_Theta', 'C4_Theta', 'Fp1_Theta','Fp2_Theta','O1_Theta','O2_Theta','P7_Theta','P8_Theta']
    df_pred = df_modelo.reset_index(drop=True)

    cols = ['Fp1_Delta', 'Fp1_Theta', 'Fp1_Alpha','Fp1_Beta','Fp1_Gamma',
        'Fp2_Delta', 'Fp2_Theta', 'Fp2_Alpha','Fp2_Beta','Fp2_Gamma',
        'C3_Delta', 'C3_Theta', 'C3_Alpha','C3_Beta','C3_Gamma',
        'C4_Delta', 'C4_Theta', 'C4_Alpha','C4_Beta','C4_Gamma',
        'P7_Delta', 'P7_Theta', 'P7_Alpha','P7_Beta','P7_Gamma',
        'P8_Delta', 'P8_Theta', 'P8_Alpha','P8_Beta','P8_Gamma',
        'O1_Delta', 'O1_Theta', 'O1_Alpha','O1_Beta','O1_Gamma',
        'O2_Delta', 'O2_Theta', 'O2_Alpha','O2_Beta','O2_Gamma',] #'C4_Delta', 'C4_Theta', 'C4_Alpha','C4_Beta','C4_Gamma',
    
    #aqui cambien el nombre del canal que eligan
    df_pred['fp1_engagement'] = df_pred['Fp1_Beta'] / (df_pred['Fp1_Theta'] + df_pred['Fp1_Alpha']) 
    df_pred['fp2_engagement'] = df_pred['Fp2_Beta'] / (df_pred['Fp2_Theta'] + df_pred['Fp2_Alpha']) 

    df_predi = df_pred[cols]*0.0000488
    iteraciones + 1
    valen = Val_Pkl.predict(df_predi)
    arous = Aro_Pkl.predict(df_predi)
    domin = Dom_Pkl.predict(df_predi)
    engag_fp1 = mean(df_pred["fp1_engagement"])
    engag_fp2 = mean(df_pred["fp2_engagement"])
    engag = (engag_fp1+engag_fp2)/2
    vale = mean(valen)
    arou = mean(arous)
    domi = mean(domin)
    emociones = emocion(arou, domi, vale)
    write_read(vale, arou, domi)
    values = [vale, arou, domin]
    client1.send_message(address, engag)
    client2.send_message(address, engag)

    realemotion = real_emotion(emociones)

    client3.send_message(address2, emociones)
    client3.send_message(address3, realemotion)

    client4.send_message(address2, emociones)
    client4.send_message(address3, realemotion)

    print(emociones)
    print(engag)
