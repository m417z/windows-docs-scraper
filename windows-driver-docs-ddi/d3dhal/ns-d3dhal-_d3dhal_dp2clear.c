typedef struct _D3DHAL_DP2CLEAR {
  DWORD    dwFlags;
  DWORD    dwFillColor;
  D3DVALUE dvFillDepth;
  DWORD    dwFillStencil;
  RECT     Rects[1];
} D3DHAL_DP2CLEAR;