typedef struct _D3DKMDT_COLORSPACE_TRANSFORM_MATRIX_V2 {
  D3DKMDT_COLORSPACE_TRANSFORM_STAGE_CONTROL StageControlLookupTable1DDegamma;
  D3DDDI_DXGI_RGB                            LookupTable1DDegamma[4096];
  D3DKMDT_COLORSPACE_TRANSFORM_STAGE_CONTROL StageControlColorMatrix3x3;
  float                                      ColorMatrix3x3[3][3];
  D3DKMDT_COLORSPACE_TRANSFORM_STAGE_CONTROL StageControlLookupTable1DRegamma;
  D3DDDI_DXGI_RGB                            LookupTable1DRegamma[4096];
} D3DKMDT_COLORSPACE_TRANSFORM_MATRIX_V2, *PD3DKMDT_COLORSPACE_TRANSFORM_MATRIX_V2;