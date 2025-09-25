NTSTATUS FLTAPI FltSetVolumeInformation(
  [in]  PFLT_INSTANCE        Instance,
  [out] PIO_STATUS_BLOCK     Iosb,
  [out] PVOID                FsInformation,
  [in]  ULONG                Length,
  [in]  FS_INFORMATION_CLASS FsInformationClass
);