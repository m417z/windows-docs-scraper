int WSCGetApplicationCategory(
  [in]  LPCWSTR Path,
  [in]  DWORD   PathLength,
  [in]  LPCWSTR Extra,
  [in]  DWORD   ExtraLength,
  [out] DWORD   *pPermittedLspCategories,
  [out] LPINT   lpErrno
);