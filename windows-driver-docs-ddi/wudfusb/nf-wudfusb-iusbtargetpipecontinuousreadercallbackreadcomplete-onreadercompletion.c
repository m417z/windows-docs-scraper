void OnReaderCompletion(
  [in] IWDFUsbTargetPipe *pPipe,
  [in] IWDFMemory        *pMemory,
  [in] SIZE_T            NumBytesTransferred,
  [in] PVOID             Context
);