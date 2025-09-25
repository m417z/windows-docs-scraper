NTSTATUS FLTAPI FltQueryInformationFile(
  [in]            PFLT_INSTANCE          Instance,
  [in]            PFILE_OBJECT           FileObject,
  [out]           PVOID                  FileInformation,
  [in]            ULONG                  Length,
  [in]            FILE_INFORMATION_CLASS FileInformationClass,
  [out, optional] PULONG                 LengthReturned
);