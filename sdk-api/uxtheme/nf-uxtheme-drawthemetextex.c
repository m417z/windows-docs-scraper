HRESULT DrawThemeTextEx(
  [in]      HTHEME        hTheme,
  [in]      HDC           hdc,
  [in]      int           iPartId,
  [in]      int           iStateId,
  [in]      LPCWSTR       pszText,
  [in]      int           cchText,
  [in]      DWORD         dwTextFlags,
  [in, out] LPRECT        pRect,
  [in]      const DTTOPTS *pOptions
);