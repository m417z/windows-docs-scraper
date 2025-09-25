void UpdateTiles(
  [in] ID3D11Resource                        *pDestTiledResource,
  [in] const D3D11_TILED_RESOURCE_COORDINATE *pDestTileRegionStartCoordinate,
  [in] const D3D11_TILE_REGION_SIZE          *pDestTileRegionSize,
  [in] const void                            *pSourceTileData,
  [in] UINT                                  Flags
);