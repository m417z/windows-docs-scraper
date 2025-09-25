HRESULT CreateGdiCompatibleTextLayout(
  [in]           WCHAR const         *string,
                 UINT32              stringLength,
                 IDWriteTextFormat   *textFormat,
                 FLOAT               layoutWidth,
                 FLOAT               layoutHeight,
                 FLOAT               pixelsPerDip,
  [in, optional] DWRITE_MATRIX const *transform,
                 BOOL                useGdiNatural,
  [out]          IDWriteTextLayout   **textLayout
);