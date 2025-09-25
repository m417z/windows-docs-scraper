Status DrawImage(
  [in]      Image                 *image,
  [in, ref] const RectF &         destRect,
  [in]      REAL                  srcx,
  [in]      REAL                  srcy,
  [in]      REAL                  srcwidth,
  [in]      REAL                  srcheight,
  [in]      Unit                  srcUnit,
  [in]      const ImageAttributes *imageAttributes,
  [in]      DrawImageAbort        callback,
  [in]      VOID                  *callbackData
);