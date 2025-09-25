HRESULT CreateBitmap(
  [in]  UINT                       uiWidth,
  [in]  UINT                       uiHeight,
  [in]  REFWICPixelFormatGUID      pixelFormat,
  [in]  WICBitmapCreateCacheOption option,
  [out] IWICBitmap                 **ppIBitmap
);