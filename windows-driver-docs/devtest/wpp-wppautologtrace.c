NTSTATUS
WppAutoLogTrace(
    _In_ PVOID  AutoLogContext,
    _In_ UCHAR  MessageLevel,
    _In_ ULONG  MessageFlags,
    _In_ LPGUID MessageGuid,
    _In_ USHORT MessageNumber,
    ...
    );