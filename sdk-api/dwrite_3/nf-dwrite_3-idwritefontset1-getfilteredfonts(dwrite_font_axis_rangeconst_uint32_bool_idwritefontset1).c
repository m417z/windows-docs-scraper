HRESULT GetFilteredFonts(
        DWRITE_FONT_AXIS_RANGE const *fontAxisRanges,
        UINT32                       fontAxisRangeCount,
        BOOL                         selectAnyRange,
  [out] IDWriteFontSet1              **filteredFontSet
);