NTSTATUS WdfIoTargetFormatRequestForWrite(
  [in]           WDFIOTARGET       IoTarget,
  [in]           WDFREQUEST        Request,
  [in, optional] WDFMEMORY         InputBuffer,
  [in, optional] PWDFMEMORY_OFFSET InputBufferOffset,
  [in, optional] PLONGLONG         DeviceOffset
);