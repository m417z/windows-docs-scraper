VOID ChangerError(
  PDEVICE_OBJECT      DeviceObject,
  PSCSI_REQUEST_BLOCK Srb,
  NTSTATUS            *Status,
  BOOLEAN             *Retry
);