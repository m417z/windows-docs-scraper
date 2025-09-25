NTSYSAPI NTSTATUS ZwSetVolumeInformationFile(
  [in]  HANDLE               FileHandle,
  [out] PIO_STATUS_BLOCK     IoStatusBlock,
  [in]  PVOID                FsInformation,
  [in]  ULONG                Length,
  [in]  FS_INFORMATION_CLASS FsInformationClass
);