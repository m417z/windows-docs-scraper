void CopyTiles(
  [in] ID3D12Resource                        *pTiledResource,
  [in] const D3D12_TILED_RESOURCE_COORDINATE *pTileRegionStartCoordinate,
  [in] const D3D12_TILE_REGION_SIZE          *pTileRegionSize,
  [in] ID3D12Resource                        *pBuffer,
       UINT64                                BufferStartOffsetInBytes,
       D3D12_TILE_COPY_FLAGS                 Flags
);