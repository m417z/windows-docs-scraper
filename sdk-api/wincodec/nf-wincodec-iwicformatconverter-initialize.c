HRESULT Initialize(
  [in] IWICBitmapSource      *pISource,
  [in] REFWICPixelFormatGUID dstFormat,
  [in] WICBitmapDitherType   dither,
  [in] IWICPalette           *pIPalette,
  [in] double                alphaThresholdPercent,
  [in] WICBitmapPaletteType  paletteTranslate
);