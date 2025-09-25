HRESULT AddFont(
  IDWriteFontFile              *fontFile,
  UINT32                       fontFaceIndex,
  DWRITE_FONT_SIMULATIONS      fontSimulations,
  DWRITE_FONT_AXIS_VALUE const *fontAxisValues,
  UINT32                       fontAxisValueCount,
  DWRITE_FONT_AXIS_RANGE const *fontAxisRanges,
  UINT32                       fontAxisRangeCount,
  DWRITE_FONT_PROPERTY const   *properties,
  UINT32                       propertyCount
);