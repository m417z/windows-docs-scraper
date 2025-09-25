NTSTATUS
KeWaitForMultipleObjects (
    ULONG Count,
    PVOID Object[],
    WaitType,
    KWAIT_REASON WaitReason,
    KPROCESSOR_MODE WaitMode,
    BOOLEAN Alertable,
    PLARGE_INTEGER Timeout,
    PKWAIT_BLOCK WaitBlockArray
    );