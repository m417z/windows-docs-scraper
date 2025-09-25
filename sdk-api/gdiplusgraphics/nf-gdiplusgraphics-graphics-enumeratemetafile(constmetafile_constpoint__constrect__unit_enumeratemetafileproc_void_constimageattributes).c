Status EnumerateMetafile(
  [in]      const Metafile        *metafile,
  [in, ref] const Point &         destPoint,
  [in, ref] const Rect &          srcRect,
  [in]      Unit                  srcUnit,
  [in]      EnumerateMetafileProc callback,
  [in]      VOID                  *callbackData,
  [in]      const ImageAttributes *imageAttributes
);