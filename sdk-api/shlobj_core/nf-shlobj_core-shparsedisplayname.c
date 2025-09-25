SHSTDAPI SHParseDisplayName(
  [in]            PCWSTR           pszName,
  [in, optional]  IBindCtx         *pbc,
  [out]           PIDLIST_ABSOLUTE *ppidl,
  [in]            SFGAOF           sfgaoIn,
  [out, optional] SFGAOF           *psfgaoOut
);