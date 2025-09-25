NTSTATUS IoCheckLinkShareAccess(
  [in]                ACCESS_MASK        DesiredAccess,
  [in]                ULONG              DesiredShareAccess,
  [in, out, optional] PFILE_OBJECT       FileObject,
  [in, out, optional] PSHARE_ACCESS      ShareAccess,
  [in, out, optional] PLINK_SHARE_ACCESS LinkShareAccess,
  [in]                ULONG              IoShareAccessFlags
);