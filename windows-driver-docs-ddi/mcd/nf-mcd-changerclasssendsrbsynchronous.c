NTSTATUS ChangerClassSendSrbSynchronous(
  [in] PDEVICE_OBJECT      DeviceObject,
  [in] PSCSI_REQUEST_BLOCK Srb,
  [in] PVOID               Buffer,
  [in] ULONG               BufferSize,
  [in] BOOLEAN             WriteToDevice
);