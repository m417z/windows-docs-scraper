NTSTATUS FLTAPI FltSetInformationFile(
  [in] PFLT_INSTANCE          Instance,
  [in] PFILE_OBJECT           FileObject,
  [in] PVOID                  FileInformation,
  [in] ULONG                  Length,
  [in] FILE_INFORMATION_CLASS FileInformationClass
);