Status DrawImage(
  [in]      Image                 *image,
  [in, ref] const Rect &          destRect,
  [in]      INT                   srcx,
  [in]      INT                   srcy,
  [in]      INT                   srcwidth,
  [in]      INT                   srcheight,
  [in]      Unit                  srcUnit,
  [in]      const ImageAttributes *imageAttributes,
  [in]      DrawImageAbort        callback,
  [in]      VOID                  *callbackData
);