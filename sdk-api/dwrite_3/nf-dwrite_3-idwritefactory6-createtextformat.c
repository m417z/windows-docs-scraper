HRESULT CreateTextFormat(
  WCHAR const                  *fontFamilyName,
  IDWriteFontCollection        *fontCollection,
  DWRITE_FONT_AXIS_VALUE const *fontAxisValues,
  UINT32                       fontAxisValueCount,
  FLOAT                        fontSize,
  WCHAR const                  *localeName,
  IDWriteTextFormat3           **textFormat
);