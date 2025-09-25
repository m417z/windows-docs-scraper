HRESULT Initialize(
  [in] IWICBitmapSource      **ppPlanes,
       UINT                  cPlanes,
       REFWICPixelFormatGUID dstFormat,
       WICBitmapDitherType   dither,
       IWICPalette           *pIPalette,
       double                alphaThresholdPercent,
       WICBitmapPaletteType  paletteTranslate
);