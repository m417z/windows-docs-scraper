typedef struct D3D12_TEXCUBE_ARRAY_SRV {
  UINT  MostDetailedMip;
  UINT  MipLevels;
  UINT  First2DArrayFace;
  UINT  NumCubes;
  FLOAT ResourceMinLODClamp;
} D3D12_TEXCUBE_ARRAY_SRV;