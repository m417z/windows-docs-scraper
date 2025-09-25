NTSTATUS FLTAPI FltQueryDirectoryFile(
  [in]            PFLT_INSTANCE          Instance,
  [in]            PFILE_OBJECT           FileObject,
  [out]           PVOID                  FileInformation,
  [in]            ULONG                  Length,
  [in]            FILE_INFORMATION_CLASS FileInformationClass,
  [in]            BOOLEAN                ReturnSingleEntry,
  [in, optional]  PUNICODE_STRING        FileName,
  [in]            BOOLEAN                RestartScan,
  [out, optional] PULONG                 LengthReturned
);