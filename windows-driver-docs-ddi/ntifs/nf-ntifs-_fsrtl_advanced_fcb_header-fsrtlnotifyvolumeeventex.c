NTSTATUS FsRtlNotifyVolumeEventEx(
  [in] PFILE_OBJECT                       FileObject,
  [in] ULONG                              EventCode,
  [in] PTARGET_DEVICE_CUSTOM_NOTIFICATION Event
);