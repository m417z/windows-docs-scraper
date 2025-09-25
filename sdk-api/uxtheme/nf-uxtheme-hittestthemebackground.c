HRESULT HitTestThemeBackground(
  [in]  HTHEME  hTheme,
  [in]  HDC     hdc,
  [in]  int     iPartId,
  [in]  int     iStateId,
  [in]  DWORD   dwOptions,
  [in]  LPCRECT pRect,
  [in]  HRGN    hrgn,
  [in]  POINT   ptTest,
  [out] WORD    *pwHitTestCode
);