NTSTATUS FLTAPI FltQueryDirectoryFileEx(
  PFLT_INSTANCE          Instance,
  PFILE_OBJECT           FileObject,
  PVOID                  FileInformation,
  ULONG                  Length,
  FILE_INFORMATION_CLASS FileInformationClass,
  ULONG                  QueryFlags,
  PUNICODE_STRING        FileName,
  PULONG                 LengthReturned
);