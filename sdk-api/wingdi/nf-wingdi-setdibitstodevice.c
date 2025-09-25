int SetDIBitsToDevice(
  [in] HDC              hdc,
  [in] int              xDest,
  [in] int              yDest,
  [in] DWORD            w,
  [in] DWORD            h,
  [in] int              xSrc,
  [in] int              ySrc,
  [in] UINT             StartScan,
  [in] UINT             cLines,
  [in] const VOID       *lpvBits,
  [in] const BITMAPINFO *lpbmi,
  [in] UINT             ColorUse
);