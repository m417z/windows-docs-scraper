NTSTATUS NtRemoveIoCompletion (
    __in HANDLE IoCompletionHandle,
    __out PVOID *KeyContext,
    __out PVOID *ApcContext,
    __out PIO_STATUS_BLOCK IoStatusBlock,
    __in_opt PLARGE_INTEGER Timeout
    )