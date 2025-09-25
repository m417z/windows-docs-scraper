HRESULT GetMatchingFonts(
  WCHAR const                  *familyName,
  DWRITE_FONT_AXIS_VALUE const *fontAxisValues,
  UINT32                       fontAxisValueCount,
  DWRITE_FONT_SIMULATIONS      allowedSimulations,
  IDWriteFontSet4              **matchingFonts
);