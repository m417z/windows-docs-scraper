BOOL ScrollDC(
  [in]  HDC        hDC,
  [in]  int        dx,
  [in]  int        dy,
  [in]  const RECT *lprcScroll,
  [in]  const RECT *lprcClip,
  [in]  HRGN       hrgnUpdate,
  [out] LPRECT     lprcUpdate
);