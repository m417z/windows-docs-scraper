typedef struct _D3DKMDT_GAMMA_RAMP {
  D3DDDI_GAMMARAMP_TYPE Type;
  SIZE_T                DataSize;
  union {
    D3DDDI_GAMMA_RAMP_RGB256x3x16          *pRgb256x3x16;
    D3DDDI_GAMMA_RAMP_DXGI_1               *pDxgi1;
    D3DKMDT_3x4_COLORSPACE_TRANSFORM       *p3x4;
    D3DKMDT_COLORSPACE_TRANSFORM_MATRIX_V2 *pMatrixV2;
    VOID                                   *pRaw;
  } Data;
} D3DKMDT_GAMMA_RAMP;