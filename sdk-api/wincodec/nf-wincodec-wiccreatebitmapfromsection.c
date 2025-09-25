HRESULT WICCreateBitmapFromSection(
  [in]  UINT                  width,
  [in]  UINT                  height,
        REFWICPixelFormatGUID pixelFormat,
  [in]  HANDLE                hSection,
  [in]  UINT                  stride,
  [in]  UINT                  offset,
  [out] IWICBitmap            **ppIBitmap
);