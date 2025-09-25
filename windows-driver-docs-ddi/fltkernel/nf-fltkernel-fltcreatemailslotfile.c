NTSTATUS FLTAPI FltCreateMailslotFile(
  [in]            PFLT_FILTER               Filter,
  [in, optional]  PFLT_INSTANCE             Instance,
  [out]           PHANDLE                   FileHandle,
  [out, optional] PFILE_OBJECT              *FileObject,
  [in]            ULONG                     DesiredAccess,
  [in]            POBJECT_ATTRIBUTES        ObjectAttributes,
  [out]           PIO_STATUS_BLOCK          IoStatusBlock,
  [in]            ULONG                     CreateOptions,
  [in]            ULONG                     MailslotQuota,
  [in]            ULONG                     MaximumMessageSize,
  [in]            PLARGE_INTEGER            ReadTimeout,
  [in, optional]  PIO_DRIVER_CREATE_CONTEXT DriverContext
);