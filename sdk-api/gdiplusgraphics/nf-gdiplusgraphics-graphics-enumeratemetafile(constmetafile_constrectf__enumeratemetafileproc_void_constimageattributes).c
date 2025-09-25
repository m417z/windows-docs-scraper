Status EnumerateMetafile(
  [in]      const Metafile        *metafile,
  [in, ref] const RectF &         destRect,
  [in]      EnumerateMetafileProc callback,
  [in]      VOID                  *callbackData,
  [in]      const ImageAttributes *imageAttributes
);