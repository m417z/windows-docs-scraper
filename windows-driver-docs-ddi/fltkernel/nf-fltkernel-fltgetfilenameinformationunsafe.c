NTSTATUS FLTAPI FltGetFileNameInformationUnsafe(
  [in]           PFILE_OBJECT               FileObject,
  [in, optional] PFLT_INSTANCE              Instance,
  [in]           FLT_FILE_NAME_OPTIONS      NameOptions,
  [out]          PFLT_FILE_NAME_INFORMATION *FileNameInformation
);