HRESULT MapCharacters(
                 IDWriteTextAnalysisSource *analysisSource,
                 UINT32                    textPosition,
                 UINT32                    textLength,
  [in, optional] IDWriteFontCollection     *baseFontCollection,
  [in, optional] wchar_t const             *baseFamilyName,
                 DWRITE_FONT_WEIGHT        baseWeight,
                 DWRITE_FONT_STYLE         baseStyle,
                 DWRITE_FONT_STRETCH       baseStretch,
  [out]          UINT32                    *mappedLength,
  [out]          IDWriteFont               **mappedFont,
  [out]          FLOAT                     *scale
);