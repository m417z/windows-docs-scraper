__kernel_entry NTSYSCALLAPI NTSTATUS NtQueryInformationByName(
  [in]  POBJECT_ATTRIBUTES     ObjectAttributes,
  [out] PIO_STATUS_BLOCK       IoStatusBlock,
  [out] PVOID                  FileInformation,
  [in]  ULONG                  Length,
  [in]  FILE_INFORMATION_CLASS FileInformationClass
);