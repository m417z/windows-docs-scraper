typedef struct _D3DDDIARG_TEXBLT {
  [in] HANDLE hDstResource;
  [in] HANDLE hSrcResource;
  [in] UINT   CubeMapFace;
  [in] POINT  DstPoint;
  [in] RECT   SrcRect;
} D3DDDIARG_TEXBLT;