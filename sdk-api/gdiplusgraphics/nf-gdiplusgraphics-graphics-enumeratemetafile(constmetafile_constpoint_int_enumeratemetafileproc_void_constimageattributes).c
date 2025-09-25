Status EnumerateMetafile(
  [in] const Metafile        *metafile,
  [in] const Point           *destPoints,
  [in] INT                   count,
  [in] EnumerateMetafileProc callback,
  [in] VOID                  *callbackData,
  [in] const ImageAttributes *imageAttributes
);