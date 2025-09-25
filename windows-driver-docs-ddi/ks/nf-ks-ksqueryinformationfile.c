KSDDKAPI NTSTATUS KsQueryInformationFile(
  [in]  PFILE_OBJECT           FileObject,
  [out] PVOID                  FileInformation,
  [in]  ULONG                  Length,
  [in]  FILE_INFORMATION_CLASS FileInformationClass
);