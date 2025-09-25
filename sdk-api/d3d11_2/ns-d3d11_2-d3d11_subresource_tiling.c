typedef struct D3D11_SUBRESOURCE_TILING {
  UINT   WidthInTiles;
  UINT16 HeightInTiles;
  UINT16 DepthInTiles;
  UINT   StartTileIndexInOverallResource;
} D3D11_SUBRESOURCE_TILING;