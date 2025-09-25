VOID IoRemoveLinkShareAccessEx(
  [in]                PFILE_OBJECT       FileObject,
  [in, out]           PSHARE_ACCESS      ShareAccess,
  [in, out, optional] PLINK_SHARE_ACCESS LinkShareAccess,
                      ULONG              IoShareAccessFlags
);