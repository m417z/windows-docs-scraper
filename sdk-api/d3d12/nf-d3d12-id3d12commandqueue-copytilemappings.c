void CopyTileMappings(
  [in] ID3D12Resource                        *pDstResource,
  [in] const D3D12_TILED_RESOURCE_COORDINATE *pDstRegionStartCoordinate,
  [in] ID3D12Resource                        *pSrcResource,
  [in] const D3D12_TILED_RESOURCE_COORDINATE *pSrcRegionStartCoordinate,
  [in] const D3D12_TILE_REGION_SIZE          *pRegionSize,
       D3D12_TILE_MAPPING_FLAGS              Flags
);