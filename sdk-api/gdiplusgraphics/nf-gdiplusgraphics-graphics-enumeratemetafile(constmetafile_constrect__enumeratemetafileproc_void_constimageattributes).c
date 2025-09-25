Status EnumerateMetafile(
  [in]      const Metafile        *metafile,
  [in, ref] const Rect &          destRect,
  [in]      EnumerateMetafileProc callback,
  [in]      VOID                  *callbackData,
  [in]      const ImageAttributes *imageAttributes
);