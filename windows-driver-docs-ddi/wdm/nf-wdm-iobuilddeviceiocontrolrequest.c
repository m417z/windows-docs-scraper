__drv_aliasesMem PIRP IoBuildDeviceIoControlRequest(
  [in]            ULONG            IoControlCode,
  [in]            PDEVICE_OBJECT   DeviceObject,
  [in, optional]  PVOID            InputBuffer,
  [in]            ULONG            InputBufferLength,
  [out, optional] PVOID            OutputBuffer,
  [in]            ULONG            OutputBufferLength,
  [in]            BOOLEAN          InternalDeviceIoControl,
  [in, optional]  PKEVENT          Event,
  [out]           PIO_STATUS_BLOCK IoStatusBlock
);