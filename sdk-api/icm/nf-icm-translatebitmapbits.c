BOOL TranslateBitmapBits(
  HTRANSFORM    hColorTransform,
  PVOID         pSrcBits,
  BMFORMAT      bmInput,
  DWORD         dwWidth,
  DWORD         dwHeight,
  DWORD         dwInputStride,
  PVOID         pDestBits,
  BMFORMAT      bmOutput,
  DWORD         dwOutputStride,
  PBMCALLBACKFN pfnCallBack,
  LPARAM        ulCallbackData
);