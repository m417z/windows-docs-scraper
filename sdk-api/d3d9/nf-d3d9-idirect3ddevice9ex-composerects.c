HRESULT ComposeRects(
  [in] IDirect3DSurface9      *pSrc,
  [in] IDirect3DSurface9      *pDst,
  [in] IDirect3DVertexBuffer9 *pSrcRectDescs,
  [in] UINT                   NumRects,
  [in] IDirect3DVertexBuffer9 *pDstRectDescs,
  [in] D3DCOMPOSERECTSOP      Operation,
  [in] int                    Xoffset,
  [in] int                    Yoffset
);