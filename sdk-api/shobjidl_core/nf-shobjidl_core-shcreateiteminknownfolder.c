SHSTDAPI SHCreateItemInKnownFolder(
  [in]           REFKNOWNFOLDERID kfid,
                 DWORD            dwKFFlags,
  [in, optional] PCWSTR           pszItem,
  [in]           REFIID           riid,
  [out]          void             **ppv
);