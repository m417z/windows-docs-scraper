NTSTATUS IoQueryVolumeInformation(
  PFILE_OBJECT         FileObject,
  FS_INFORMATION_CLASS FsInformationClass,
  ULONG                Length,
  PVOID                FsInformation,
  PULONG               ReturnedLength
);