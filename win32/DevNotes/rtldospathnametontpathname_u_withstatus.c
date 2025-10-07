NTSTATUS RtlDosPathNameToNtPathName_U_WithStatus(
    __in PCWSTR DosFileName,
    __out PUNICODE_STRING NtFileName,
    __deref_opt_out_opt PWSTR *FilePart,
    __reserved PVOID Reserved
    )