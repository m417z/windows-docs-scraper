NTSTATUS FLTAPI FltGetVolumeFromDeviceObject(
  [in]  PFLT_FILTER    Filter,
  [in]  PDEVICE_OBJECT DeviceObject,
  [out] PFLT_VOLUME    *RetVolume
);