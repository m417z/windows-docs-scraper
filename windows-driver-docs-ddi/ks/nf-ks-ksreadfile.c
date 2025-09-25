KSDDKAPI NTSTATUS KsReadFile(
  [in]           PFILE_OBJECT     FileObject,
  [in, optional] PKEVENT          Event,
  [in, optional] PVOID            PortContext,
  [out]          PIO_STATUS_BLOCK IoStatusBlock,
  [out]          PVOID            Buffer,
  [in]           ULONG            Length,
  [in, optional] ULONG            Key,
  [in]           KPROCESSOR_MODE  RequestorMode
);