typedef struct _D3DDDIARG_DISCARD {
  HANDLE     hResource;
  UINT       FirstSubResource;
  UINT       NumSubResources;
  const RECT *pRects;
  UINT       NumRects;
} D3DDDIARG_DISCARD;