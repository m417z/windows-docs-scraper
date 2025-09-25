VOID IoSetLinkShareAccess(
  [in]                ACCESS_MASK        DesiredAccess,
  [in]                ULONG              DesiredShareAccess,
  [in, out]           PFILE_OBJECT       FileObject,
  [in, out]           PSHARE_ACCESS      ShareAccess,
  [in, out, optional] PLINK_SHARE_ACCESS LinkShareAccess,
  [in]                ULONG              IoShareAccessFlags
);