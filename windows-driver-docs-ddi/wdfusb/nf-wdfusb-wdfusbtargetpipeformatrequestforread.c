NTSTATUS WdfUsbTargetPipeFormatRequestForRead(
  [in]           WDFUSBPIPE        Pipe,
  [in]           WDFREQUEST        Request,
  [in, optional] WDFMEMORY         ReadMemory,
  [in, optional] PWDFMEMORY_OFFSET ReadOffset
);