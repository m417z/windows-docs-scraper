NTSTATUS WdfUsbTargetPipeFormatRequestForWrite(
  [in]           WDFUSBPIPE        Pipe,
  [in]           WDFREQUEST        Request,
  [in, optional] WDFMEMORY         WriteMemory,
  [in, optional] PWDFMEMORY_OFFSET WriteOffset
);