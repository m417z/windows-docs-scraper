BOOL UpdateLayeredWindow(
  [in]           HWND          hWnd,
  [in, optional] HDC           hdcDst,
  [in, optional] POINT         *pptDst,
  [in, optional] SIZE          *psize,
  [in, optional] HDC           hdcSrc,
  [in, optional] POINT         *pptSrc,
  [in]           COLORREF      crKey,
  [in, optional] BLENDFUNCTION *pblend,
  [in]           DWORD         dwFlags
);