HRESULT Analyze(
  [out]           BOOL                  *isSupportedFontType,
  [out]           DWRITE_FONT_FILE_TYPE *fontFileType,
  [out, optional] DWRITE_FONT_FACE_TYPE *fontFaceType,
  [out]           UINT32                *numberOfFaces
);