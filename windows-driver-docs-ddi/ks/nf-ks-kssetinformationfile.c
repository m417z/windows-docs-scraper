KSDDKAPI NTSTATUS KsSetInformationFile(
  [in] PFILE_OBJECT           FileObject,
  [in] PVOID                  FileInformation,
  [in] ULONG                  Length,
  [in] FILE_INFORMATION_CLASS FileInformationClass
);