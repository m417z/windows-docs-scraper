__kernel_entry NTSTATUS NtNotifyChangeMultipleKeys(
  [in]            HANDLE               MasterKeyHandle,
  [in, optional]  ULONG                Count,
  [in, optional]  OBJECT_ATTRIBUTES [] SubordinateObjects,
  [in, optional]  HANDLE               Event,
  [in, optional]  PIO_APC_ROUTINE      ApcRoutine,
  [in, optional]  PVOID                ApcContext,
  [out]           PIO_STATUS_BLOCK     IoStatusBlock,
  [in]            ULONG                CompletionFilter,
  [in]            BOOLEAN              WatchTree,
  [out, optional] PVOID                Buffer,
  [in]            ULONG                BufferSize,
  [in]            BOOLEAN              Asynchronous
);