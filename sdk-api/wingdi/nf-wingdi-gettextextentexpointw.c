BOOL GetTextExtentExPointW(
  [in]  HDC     hdc,
  [in]  LPCWSTR lpszString,
  [in]  int     cchString,
  [in]  int     nMaxExtent,
  [out] LPINT   lpnFit,
  [out] LPINT   lpnDx,
  [out] LPSIZE  lpSize
);