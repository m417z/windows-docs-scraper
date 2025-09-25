NTSTATUS IoCheckShareAccess(
  [in]      ACCESS_MASK   DesiredAccess,
  [in]      ULONG         DesiredShareAccess,
  [in, out] PFILE_OBJECT  FileObject,
  [in, out] PSHARE_ACCESS ShareAccess,
  [in]      BOOLEAN       Update
);