HRESULT GetTextComplexity(
  [in]            WCHAR const     *textString,
                  UINT32          textLength,
                  IDWriteFontFace *fontFace,
  [out]           BOOL            *isTextSimple,
  [out]           UINT32          *textLengthRead,
  [out, optional] UINT16          *glyphIndices
);