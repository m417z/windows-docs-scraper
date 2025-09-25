HRESULT StgOpenStorage(
  [in]  const WCHAR *pwcsName,
  [in]  IStorage    *pstgPriority,
  [in]  DWORD       grfMode,
  [in]  SNB         snbExclude,
  [in]  DWORD       reserved,
  [out] IStorage    **ppstgOpen
);