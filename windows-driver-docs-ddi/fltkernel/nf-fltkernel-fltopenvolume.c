NTSTATUS FLTAPI FltOpenVolume(
  [in]  PFLT_INSTANCE Instance,
  [out] PHANDLE       VolumeHandle,
  [out] PFILE_OBJECT  *VolumeFileObject
);