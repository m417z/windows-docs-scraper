BOOL CheckBitmapBits(
  HTRANSFORM    hColorTransform,
  PVOID         pSrcBits,
  BMFORMAT      bmInput,
  DWORD         dwWidth,
  DWORD         dwHeight,
  DWORD         dwStride,
  PBYTE         paResult,
  PBMCALLBACKFN pfnCallback,
  LPARAM        lpCallbackData
);