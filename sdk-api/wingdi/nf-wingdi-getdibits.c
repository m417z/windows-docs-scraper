int GetDIBits(
  [in]      HDC          hdc,
  [in]      HBITMAP      hbm,
  [in]      UINT         start,
  [in]      UINT         cLines,
  [out]     LPVOID       lpvBits,
  [in, out] LPBITMAPINFO lpbmi,
  [in]      UINT         usage
);