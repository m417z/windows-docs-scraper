NTSTATUS FLTAPI FltGetVolumeFromFileObject(
  [in]  PFLT_FILTER  Filter,
  [in]  PFILE_OBJECT FileObject,
  [out] PFLT_VOLUME  *RetVolume
);