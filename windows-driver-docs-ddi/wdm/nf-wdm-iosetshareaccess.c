VOID IoSetShareAccess(
  [in]      ACCESS_MASK   DesiredAccess,
  [in]      ULONG         DesiredShareAccess,
  [in, out] PFILE_OBJECT  FileObject,
  [out]     PSHARE_ACCESS ShareAccess
);