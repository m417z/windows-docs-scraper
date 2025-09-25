HRESULT CreateFontFileReference(
  [in]           WCHAR const     *filePath,
  [in, optional] FILETIME const  *lastWriteTime,
  [out]          IDWriteFontFile **fontFile
);