void CopyTiles(
  [in] ID3D11Resource                        *pTiledResource,
  [in] const D3D11_TILED_RESOURCE_COORDINATE *pTileRegionStartCoordinate,
  [in] const D3D11_TILE_REGION_SIZE          *pTileRegionSize,
  [in] ID3D11Buffer                          *pBuffer,
  [in] UINT64                                BufferStartOffsetInBytes,
  [in] UINT                                  Flags
);