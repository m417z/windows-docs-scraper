HRESULT GetThemeTextExtent(
  [in]  HTHEME  hTheme,
  [in]  HDC     hdc,
  [in]  int     iPartId,
  [in]  int     iStateId,
  [in]  LPCWSTR pszText,
  [in]  int     cchCharCount,
  [in]  DWORD   dwTextFlags,
  [in]  LPCRECT pBoundingRect,
  [out] LPRECT  pExtentRect
);