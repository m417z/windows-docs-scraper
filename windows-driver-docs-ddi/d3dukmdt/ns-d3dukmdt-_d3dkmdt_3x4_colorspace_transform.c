typedef struct _D3DKMDT_3X4_COLORSPACE_TRANSFORM {
       float           ColorMatrix3x4[3][4];
  [in] float           ScalarMultiplier;
       D3DDDI_DXGI_RGB LookupTable1D[4096];
} D3DKMDT_3x4_COLORSPACE_TRANSFORM, *PD3DDDI_3x4_COLORSPACE_TRANSFORM;