NTSTATUS FLTAPI FltGetDestinationFileNameInformation(
  [in]           PFLT_INSTANCE              Instance,
  [in]           PFILE_OBJECT               FileObject,
  [in, optional] HANDLE                     RootDirectory,
  [in]           PWSTR                      FileName,
  [in]           ULONG                      FileNameLength,
  [in]           FLT_FILE_NAME_OPTIONS      NameOptions,
  [out]          PFLT_FILE_NAME_INFORMATION *RetFileNameInformation
);