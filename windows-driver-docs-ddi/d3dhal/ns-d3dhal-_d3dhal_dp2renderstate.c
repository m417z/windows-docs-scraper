typedef struct _D3DHAL_DP2RENDERSTATE {
  D3DRENDERSTATETYPE RenderState;
  union {
    D3DVALUE dvState;
    DWORD    dwState;
  };
} D3DHAL_DP2RENDERSTATE;