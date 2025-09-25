int ScrollWindowEx(
  [in]  HWND       hWnd,
  [in]  int        dx,
  [in]  int        dy,
  [in]  const RECT *prcScroll,
  [in]  const RECT *prcClip,
  [in]  HRGN       hrgnUpdate,
  [out] LPRECT     prcUpdate,
  [in]  UINT       flags
);