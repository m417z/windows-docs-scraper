NTSTATUS WdfIoTargetFormatRequestForInternalIoctl(
  [in]           WDFIOTARGET       IoTarget,
  [in]           WDFREQUEST        Request,
  [in]           ULONG             IoctlCode,
  [in, optional] WDFMEMORY         InputBuffer,
  [in, optional] PWDFMEMORY_OFFSET InputBufferOffset,
  [in, optional] WDFMEMORY         OutputBuffer,
  [in, optional] PWDFMEMORY_OFFSET OutputBufferOffset
);