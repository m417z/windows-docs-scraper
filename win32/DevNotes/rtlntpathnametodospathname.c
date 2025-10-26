NTSTATUS RtlNtPathNameToDosPathName(
    IN              ULONG                      Flags,
    IN OUT          PRTL_UNICODE_STRING_BUFFER Path,
    OUT OPTIONAL    ULONG*                     Disposition,
    IN OUT OPTIONAL PWSTR*                     FilePart
    );