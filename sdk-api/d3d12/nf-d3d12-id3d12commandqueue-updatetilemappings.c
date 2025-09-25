void UpdateTileMappings(
  [in]           ID3D12Resource                        *pResource,
                 UINT                                  NumResourceRegions,
  [in, optional] const D3D12_TILED_RESOURCE_COORDINATE *pResourceRegionStartCoordinates,
  [in, optional] const D3D12_TILE_REGION_SIZE          *pResourceRegionSizes,
  [in, optional] ID3D12Heap                            *pHeap,
                 UINT                                  NumRanges,
  [in, optional] const D3D12_TILE_RANGE_FLAGS          *pRangeFlags,
  [in, optional] const UINT                            *pHeapRangeStartOffsets,
  [in, optional] const UINT                            *pRangeTileCounts,
                 D3D12_TILE_MAPPING_FLAGS              Flags
);