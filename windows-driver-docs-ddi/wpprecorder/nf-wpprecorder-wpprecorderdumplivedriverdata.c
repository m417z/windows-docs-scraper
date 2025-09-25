__drv_maxIRQL(HIGH_LEVEL)
NTSTATUS
WppRecorderDumpLiveDriverData(
    _Out_ __deref_ecount(*OutBufferLength)
        PVOID              * OutBuffer,
    _Out_
        PULONG               OutBufferLength,
    _Out_
        LPGUID               Guid
    );