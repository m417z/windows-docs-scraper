BOOL CMTranslateRGBsExt(
  HCMTRANSFORM   hcmTransform,
  LPVOID         lpSrcBits,
  BMFORMAT       bmInput,
  DWORD          dwWidth,
  DWORD          dwHeight,
  DWORD          dwInputStride,
  LPVOID         lpDestBits,
  BMFORMAT       bmOutput,
  DWORD          dwOutputStride,
  LPBMCALLBACKFN lpfnCallback,
  LPARAM         ulCallbackData
);