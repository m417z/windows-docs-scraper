BOOL ExtTextOutW(
  [in] HDC        hdc,
  [in] int        x,
  [in] int        y,
  [in] UINT       options,
  [in] const RECT *lprect,
  [in] LPCWSTR    lpString,
  [in] UINT       c,
  [in] const INT  *lpDx
);