typedef struct D3DX11_FFT_DESC {
  UINT                 NumDimensions;
  UINT                 ElementLengths[D3DX11_FFT_MAX_DIMENSIONS];
  UINT                 DimensionMask;
  D3DX11_FFT_DATA_TYPE Type;
} D3DX11_FFT_DESC;