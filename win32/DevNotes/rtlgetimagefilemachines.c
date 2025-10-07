NTSTATUS
RtlGetImageFileMachines (
    _In_ PCWSTR DosFileName,
    _Out_ IMAGE_FILE_MACHINES * MachineTypeFlags
    );