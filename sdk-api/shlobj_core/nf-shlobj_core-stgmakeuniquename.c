HRESULT StgMakeUniqueName(
  [in]  IStorage *pstgParent,
  [in]  PCWSTR   pszFileSpec,
  [in]  DWORD    grfMode,
  [in]  REFIID   riid,
  [out] void     **ppv
);