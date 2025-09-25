void OnDeviceIoControl(
  [in] IWDFIoQueue   *pWdfQueue,
  [in] IWDFIoRequest *pWdfRequest,
  [in] ULONG         ControlCode,
       SIZE_T        InputBufferSizeInBytes,
       SIZE_T        OutputBufferSizeInBytes
);