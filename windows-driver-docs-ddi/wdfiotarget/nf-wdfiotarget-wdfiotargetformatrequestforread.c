NTSTATUS WdfIoTargetFormatRequestForRead(
  [in]           WDFIOTARGET       IoTarget,
  [in]           WDFREQUEST        Request,
  [in, optional] WDFMEMORY         OutputBuffer,
  [in, optional] PWDFMEMORY_OFFSET OutputBufferOffset,
  [in, optional] PLONGLONG         DeviceOffset
);