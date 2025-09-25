HRESULT OpenStorage(
  [in]  const OLECHAR *pwcsName,
  [in]  IStorage      *pstgPriority,
  [in]  DWORD         grfMode,
  [in]  SNB           snbExclude,
  [in]  DWORD         reserved,
  [out] IStorage      **ppstg
);