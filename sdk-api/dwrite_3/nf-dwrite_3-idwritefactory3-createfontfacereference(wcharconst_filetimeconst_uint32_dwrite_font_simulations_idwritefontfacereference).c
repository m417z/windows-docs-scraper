HRESULT CreateFontFaceReference(
  WCHAR const              *filePath,
  FILETIME const           *lastWriteTime,
  UINT32                   faceIndex,
  DWRITE_FONT_SIMULATIONS  fontSimulations,
  IDWriteFontFaceReference **fontFaceReference
);