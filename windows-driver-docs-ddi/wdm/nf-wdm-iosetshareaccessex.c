VOID IoSetShareAccessEx(
  [in]           ACCESS_MASK   DesiredAccess,
  [in]           ULONG         DesiredShareAccess,
  [in, out]      PFILE_OBJECT  FileObject,
  [out]          PSHARE_ACCESS ShareAccess,
  [in, optional] PBOOLEAN      WritePermission
);