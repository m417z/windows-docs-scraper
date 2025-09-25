NTSTATUS IoSetShadowFileInformation(
  [in] PFILE_OBJECT FileObject,
  [in] PFILE_OBJECT BackingFileObject,
  [in] PVOID        BackingFltInstance
);