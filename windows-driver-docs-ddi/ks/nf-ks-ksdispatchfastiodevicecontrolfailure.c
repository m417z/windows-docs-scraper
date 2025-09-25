KSDDKAPI BOOLEAN KsDispatchFastIoDeviceControlFailure(
  [in]            PFILE_OBJECT     FileObject,
  [in]            BOOLEAN          Wait,
  [in, optional]  PVOID            InputBuffer,
  [in]            ULONG            InputBufferLength,
  [out, optional] PVOID            OutputBuffer,
  [in]            ULONG            OutputBufferLength,
  [in]            ULONG            IoControlCode,
  [out]           PIO_STATUS_BLOCK IoStatus,
  [in]            PDEVICE_OBJECT   DeviceObject
);