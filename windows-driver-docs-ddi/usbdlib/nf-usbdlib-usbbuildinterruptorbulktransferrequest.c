void UsbBuildInterruptOrBulkTransferRequest(
  [in, out]      urb,
  [in]           length,
  [in]           pipeHandle,
  [in, optional] transferBuffer,
  [in, optional] transferBufferMDL,
  [in]           transferBufferLength,
  [in]           transferFlags,
  [in]           link
);