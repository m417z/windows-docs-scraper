DSPARSE BOOL DsCrackUnquotedMangledRdnW(
  [in]            LPCWSTR       pszRDN,
  [in]            DWORD         cchRDN,
  [out, optional] GUID          *pGuid,
  [out, optional] DS_MANGLE_FOR *peDsMangleFor
);