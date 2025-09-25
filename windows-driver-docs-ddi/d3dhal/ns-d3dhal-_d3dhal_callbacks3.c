typedef struct _D3DHAL_CALLBACKS3 {
  DWORD                                dwSize;
  DWORD                                dwFlags;
  LPD3DHAL_CLEAR2CB                    Clear2;
  LPVOID                               lpvReserved;
  LPD3DHAL_VALIDATETEXTURESTAGESTATECB ValidateTextureStageState;
  LPD3DHAL_DRAWPRIMITIVES2CB           DrawPrimitives2;
} D3DHAL_CALLBACKS3, *LPD3DHAL_CALLBACKS3;