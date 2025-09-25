HRESULT GetMatchingFonts(
  DWRITE_FONT_PROPERTY const   *fontProperty,
  DWRITE_FONT_AXIS_VALUE const *fontAxisValues,
  UINT32                       fontAxisValueCount,
  IDWriteFontSet1              **matchingFonts
);