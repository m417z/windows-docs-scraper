HRESULT GetMatchingFonts(
        WCHAR const                  *familyName,
        DWRITE_FONT_AXIS_VALUE const *fontAxisValues,
        UINT32                       fontAxisValueCount,
  [out] IDWriteFontList2             **fontList
);