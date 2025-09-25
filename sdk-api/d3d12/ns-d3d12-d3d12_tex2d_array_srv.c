typedef struct D3D12_TEX2D_ARRAY_SRV {
  UINT  MostDetailedMip;
  UINT  MipLevels;
  UINT  FirstArraySlice;
  UINT  ArraySize;
  UINT  PlaneSlice;
  FLOAT ResourceMinLODClamp;
} D3D12_TEX2D_ARRAY_SRV;