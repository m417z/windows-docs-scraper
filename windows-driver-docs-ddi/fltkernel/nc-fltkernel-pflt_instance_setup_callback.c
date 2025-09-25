PFLT_INSTANCE_SETUP_CALLBACK PfltInstanceSetupCallback;

NTSTATUS PfltInstanceSetupCallback(
  [in] PCFLT_RELATED_OBJECTS FltObjects,
  [in] FLT_INSTANCE_SETUP_FLAGS Flags,
  [in] DEVICE_TYPE VolumeDeviceType,
  [in] FLT_FILESYSTEM_TYPE VolumeFilesystemType
)
{...}