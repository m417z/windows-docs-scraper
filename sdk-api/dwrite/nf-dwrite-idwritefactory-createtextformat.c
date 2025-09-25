HRESULT CreateTextFormat(
  [in]  WCHAR const           *fontFamilyName,
        IDWriteFontCollection *fontCollection,
        DWRITE_FONT_WEIGHT    fontWeight,
        DWRITE_FONT_STYLE     fontStyle,
        DWRITE_FONT_STRETCH   fontStretch,
        FLOAT                 fontSize,
  [in]  WCHAR const           *localeName,
  [out] IDWriteTextFormat     **textFormat
);