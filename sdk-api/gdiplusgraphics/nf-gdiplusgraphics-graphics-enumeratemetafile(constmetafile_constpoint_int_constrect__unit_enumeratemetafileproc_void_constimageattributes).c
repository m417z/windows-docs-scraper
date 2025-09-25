Status EnumerateMetafile(
  [in]      const Metafile        *metafile,
  [in]      const Point           *destPoints,
  [in]      INT                   count,
  [in, ref] const Rect &          srcRect,
  [in]      Unit                  srcUnit,
  [in]      EnumerateMetafileProc callback,
  [in]      VOID                  *callbackData,
  [in]      const ImageAttributes *imageAttributes
);