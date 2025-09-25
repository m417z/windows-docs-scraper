Status EnumerateMetafile(
  [in]      const Metafile        *metafile,
  [in, ref] const Point &         destPoint,
  [in]      EnumerateMetafileProc callback,
  [in]      VOID                  *callbackData,
  [in]      const ImageAttributes *imageAttributes
);