HRESULT CopyTileMappings(
  [in] ID3D11Resource                        *pDestTiledResource,
  [in] const D3D11_TILED_RESOURCE_COORDINATE *pDestRegionStartCoordinate,
  [in] ID3D11Resource                        *pSourceTiledResource,
  [in] const D3D11_TILED_RESOURCE_COORDINATE *pSourceRegionStartCoordinate,
  [in] const D3D11_TILE_REGION_SIZE          *pTileRegionSize,
  [in] UINT                                  Flags
);