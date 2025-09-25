DSPARSE BOOL DsCrackUnquotedMangledRdnA(
  [in]            LPCSTR        pszRDN,
  [in]            DWORD         cchRDN,
  [out, optional] GUID          *pGuid,
  [out, optional] DS_MANGLE_FOR *peDsMangleFor
);