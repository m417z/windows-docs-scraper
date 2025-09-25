Status DrawImage(
  [in] Image                 *image,
  [in] const PointF          *destPoints,
  [in] INT                   count,
  [in] REAL                  srcx,
  [in] REAL                  srcy,
  [in] REAL                  srcwidth,
  [in] REAL                  srcheight,
  [in] Unit                  srcUnit,
  [in] const ImageAttributes *imageAttributes,
  [in] DrawImageAbort        callback,
  [in] VOID                  *callbackData
);