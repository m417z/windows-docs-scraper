HRESULT CreateTextLayout(
  [in]  WCHAR const       *string,
        UINT32            stringLength,
        IDWriteTextFormat *textFormat,
        FLOAT             maxWidth,
        FLOAT             maxHeight,
  [out] IDWriteTextLayout **textLayout
);