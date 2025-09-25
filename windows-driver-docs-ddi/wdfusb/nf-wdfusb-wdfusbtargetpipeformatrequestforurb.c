NTSTATUS WdfUsbTargetPipeFormatRequestForUrb(
                 WDFUSBPIPE        PIPE,
  [in]           WDFREQUEST        Request,
  [in]           WDFMEMORY         UrbMemory,
  [in, optional] PWDFMEMORY_OFFSET UrbMemoryOffset
);