NTSTATUS FLTAPI FltQueryVolumeInformationFile(
  [in]            PFLT_INSTANCE        Instance,
  [in]            PFILE_OBJECT         FileObject,
  [out]           PVOID                FsInformation,
  [in]            ULONG                Length,
  [in]            FS_INFORMATION_CLASS FsInformationClass,
  [out, optional] PULONG               LengthReturned
);