HRESULT CreateFontFromLOGFONT(
  [in]           LOGFONTW const        *logFont,
  [in, optional] IDWriteFontCollection *fontCollection,
  [out]          IDWriteFont           **font
);