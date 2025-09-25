NTSTATUS IoQueryFileInformation(
  PFILE_OBJECT           FileObject,
  FILE_INFORMATION_CLASS FileInformationClass,
  ULONG                  Length,
  PVOID                  FileInformation,
  PULONG                 ReturnedLength
);