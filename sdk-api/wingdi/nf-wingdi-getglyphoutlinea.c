DWORD GetGlyphOutlineA(
  [in]  HDC            hdc,
  [in]  UINT           uChar,
  [in]  UINT           fuFormat,
  [out] LPGLYPHMETRICS lpgm,
  [in]  DWORD          cjBuffer,
  [out] LPVOID         pvBuffer,
  [in]  const MAT2     *lpmat2
);