int WSCSetApplicationCategory(
  [in]  LPCWSTR Path,
  [in]  DWORD   PathLength,
  [in]  LPCWSTR Extra,
  [in]  DWORD   ExtraLength,
  [in]  DWORD   PermittedLspCategories,
  [out] DWORD   *pPrevPermLspCat,
  [out] LPINT   lpErrno
);