typedef struct DXGI_PRESENT_PARAMETERS {
  UINT  DirtyRectsCount;
  RECT  *pDirtyRects;
  RECT  *pScrollRect;
  POINT *pScrollOffset;
} DXGI_PRESENT_PARAMETERS;