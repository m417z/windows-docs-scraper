Status EnumerateMetafile(
  [in]      const Metafile        *metafile,
  [in, ref] const PointF &        destPoint,
  [in, ref] const RectF &         srcRect,
  [in]      Unit                  srcUnit,
  [in]      EnumerateMetafileProc callback,
  [in]      VOID                  *callbackData,
  [in]      const ImageAttributes *imageAttributes
);