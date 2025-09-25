NTSTATUS FsRtlChangeBackingFileObject(
  PFILE_OBJECT              CurrentFileObject,
  PFILE_OBJECT              NewFileObject,
  FSRTL_CHANGE_BACKING_TYPE ChangeBackingType,
  ULONG                     Flags
);