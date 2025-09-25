int StretchDIBits(
  [in] HDC              hdc,
  [in] int              xDest,
  [in] int              yDest,
  [in] int              DestWidth,
  [in] int              DestHeight,
  [in] int              xSrc,
  [in] int              ySrc,
  [in] int              SrcWidth,
  [in] int              SrcHeight,
  [in] const VOID       *lpBits,
  [in] const BITMAPINFO *lpbmi,
  [in] UINT             iUsage,
  [in] DWORD            rop
);