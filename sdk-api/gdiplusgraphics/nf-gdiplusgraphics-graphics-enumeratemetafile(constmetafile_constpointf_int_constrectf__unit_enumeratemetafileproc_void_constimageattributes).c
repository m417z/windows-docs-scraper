Status EnumerateMetafile(
  [in]      const Metafile        *metafile,
  [in]      const PointF          *destPoints,
  [in]      INT                   count,
  [in, ref] const RectF &         srcRect,
  [in]      Unit                  srcUnit,
  [in]      EnumerateMetafileProc callback,
  [in]      VOID                  *callbackData,
  [in]      const ImageAttributes *imageAttributes
);