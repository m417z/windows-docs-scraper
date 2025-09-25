typedef struct D3D11_PACKED_MIP_DESC {
  UINT8 NumStandardMips;
  UINT8 NumPackedMips;
  UINT  NumTilesForPackedMips;
  UINT  StartTileIndexInOverallResource;
} D3D11_PACKED_MIP_DESC;