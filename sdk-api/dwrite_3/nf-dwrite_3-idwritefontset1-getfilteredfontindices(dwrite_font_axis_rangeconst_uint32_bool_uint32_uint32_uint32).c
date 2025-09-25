HRESULT GetFilteredFontIndices(
        DWRITE_FONT_AXIS_RANGE const *fontAxisRanges,
        UINT32                       fontAxisRangeCount,
        BOOL                         selectAnyRange,
  [out] UINT32                       *indices,
        UINT32                       maxIndexCount,
  [out] UINT32                       *actualIndexCount
);