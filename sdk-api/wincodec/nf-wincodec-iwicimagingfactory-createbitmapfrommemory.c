HRESULT CreateBitmapFromMemory(
  [in]  UINT                  uiWidth,
  [in]  UINT                  uiHeight,
  [in]  REFWICPixelFormatGUID pixelFormat,
  [in]  UINT                  cbStride,
  [in]  UINT                  cbBufferSize,
  [in]  BYTE                  *pbBuffer,
  [out] IWICBitmap            **ppIBitmap
);