HBITMAP CreateDIBSection(
  [in]  HDC              hdc,
  [in]  const BITMAPINFO *pbmi,
  [in]  UINT             usage,
  [out] VOID             **ppvBits,
  [in]  HANDLE           hSection,
  [in]  DWORD            offset
);