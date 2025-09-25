Status EnumerateMetafile(
  [in]      const Metafile        *metafile,
  [in, ref] const Rect &          destRect,
  [in, ref] const Rect &          srcRect,
  [in]      Unit                  srcUnit,
  [in]      EnumerateMetafileProc callback,
  [in]      VOID                  *callbackData,
  [in]      const ImageAttributes *imageAttributes
);