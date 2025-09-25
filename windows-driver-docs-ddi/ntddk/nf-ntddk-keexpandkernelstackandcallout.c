NTSTATUS
KeExpandKernelStackAndCallout (
    _In_ PEXPAND_STACK_CALLOUT Callout,
    _In_opt_ PVOID Parameter,
    _In_ SIZE_T Size
    );