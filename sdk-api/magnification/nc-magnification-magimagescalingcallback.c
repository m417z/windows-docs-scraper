MagImageScalingCallback Magimagescalingcallback;

BOOL Magimagescalingcallback(
  [in]  HWND hwnd,
  [in]  void *srcdata,
  [in]  MAGIMAGEHEADER srcheader,
  [out] void *destdata,
  [in]  MAGIMAGEHEADER destheader,
  [in]  RECT unclipped,
  [in]  RECT clipped,
  [in]  HRGN dirty
)
{...}