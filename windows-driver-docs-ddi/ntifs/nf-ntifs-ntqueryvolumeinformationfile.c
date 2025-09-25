__kernel_entry NTSYSCALLAPI NTSTATUS NtQueryVolumeInformationFile(
  [in]  HANDLE               FileHandle,
  [out] PIO_STATUS_BLOCK     IoStatusBlock,
  [out] PVOID                FsInformation,
  [in]  ULONG                Length,
  [in]  FS_INFORMATION_CLASS FsInformationClass
);