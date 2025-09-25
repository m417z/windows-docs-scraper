HRESULT GetMatchingFonts(
  WCHAR const         *familyName,
  DWRITE_FONT_WEIGHT  fontWeight,
  DWRITE_FONT_STRETCH fontStretch,
  DWRITE_FONT_STYLE   fontStyle,
  IDWriteFontSet      **filteredSet
);