HRESULT WICCreateBitmapFromSectionEx(
  [in]  UINT                  width,
  [in]  UINT                  height,
        REFWICPixelFormatGUID pixelFormat,
  [in]  HANDLE                hSection,
  [in]  UINT                  stride,
  [in]  UINT                  offset,
  [in]  WICSectionAccessLevel desiredAccessLevel,
  [out] IWICBitmap            **ppIBitmap
);