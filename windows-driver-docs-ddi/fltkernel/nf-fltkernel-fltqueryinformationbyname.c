NTSTATUS FLTAPI FltQueryInformationByName(
  [in]           PFLT_FILTER               Filter,
  [in, optional] PFLT_INSTANCE             Instance,
  [in]           POBJECT_ATTRIBUTES        ObjectAttributes,
  [out]          PIO_STATUS_BLOCK          IoStatusBlock,
  [out]          PVOID                     FileInformation,
  [in]           ULONG                     Length,
  [in]           FILE_INFORMATION_CLASS    FileInformationClass,
  [in, optional] PIO_DRIVER_CREATE_CONTEXT DriverContext
);