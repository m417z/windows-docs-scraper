NTSTATUS FLTAPI FltCreateFile(
  [in]           PFLT_FILTER        Filter,
  [in, optional] PFLT_INSTANCE      Instance,
  [out]          PHANDLE            FileHandle,
  [in]           ACCESS_MASK        DesiredAccess,
  [in]           POBJECT_ATTRIBUTES ObjectAttributes,
  [out]          PIO_STATUS_BLOCK   IoStatusBlock,
  [in, optional] PLARGE_INTEGER     AllocationSize,
  [in]           ULONG              FileAttributes,
  [in]           ULONG              ShareAccess,
  [in]           ULONG              CreateDisposition,
  [in]           ULONG              CreateOptions,
  [in, optional] PVOID              EaBuffer,
  [in]           ULONG              EaLength,
  [in]           ULONG              Flags
);