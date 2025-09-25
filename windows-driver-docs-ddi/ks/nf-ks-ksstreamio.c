KSDDKAPI NTSTATUS KsStreamIo(
  [in]           PFILE_OBJECT            FileObject,
  [in, optional] PKEVENT                 Event,
  [in, optional] PVOID                   PortContext,
  [in, optional] PIO_COMPLETION_ROUTINE  CompletionRoutine,
  [in, optional] PVOID                   CompletionContext,
  [in, optional] KSCOMPLETION_INVOCATION CompletionInvocationFlags,
  [out]          PIO_STATUS_BLOCK        IoStatusBlock,
  [in, out]      PVOID                   StreamHeaders,
  [in]           ULONG                   Length,
  [in]           ULONG                   Flags,
  [in]           KPROCESSOR_MODE         RequestorMode
);