NTSTATUS NtCreateNamedPipeFile(
  [out]          PHANDLE            FileHandle,
  [in]           ULONG              DesiredAccess,
  [in]           POBJECT_ATTRIBUTES ObjectAttributes,
  [out]          PIO_STATUS_BLOCK   IoStatusBlock,
  [in]           ULONG              ShareAccess,
  [in]           ULONG              CreateDisposition,
  [in]           ULONG              CreateOptions,
  [in]           ULONG              NamedPipeType,
  [in]           ULONG              ReadMode,
  [in]           ULONG              CompletionMode,
  [in]           ULONG              MaximumInstances,
  [in]           ULONG              InboundQuota,
  [in]           ULONG              OutboundQuota,
  [in, optional] PLARGE_INTEGER     DefaultTimeout
);