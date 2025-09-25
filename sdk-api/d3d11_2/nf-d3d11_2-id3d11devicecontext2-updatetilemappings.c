HRESULT UpdateTileMappings(
  [in]           ID3D11Resource                        *pTiledResource,
  [in]           UINT                                  NumTiledResourceRegions,
  [in, optional] const D3D11_TILED_RESOURCE_COORDINATE *pTiledResourceRegionStartCoordinates,
  [in, optional] const D3D11_TILE_REGION_SIZE          *pTiledResourceRegionSizes,
  [in, optional] ID3D11Buffer                          *pTilePool,
  [in]           UINT                                  NumRanges,
  [in, optional] const UINT                            *pRangeFlags,
  [in, optional] const UINT                            *pTilePoolStartOffsets,
  [in, optional] const UINT                            *pRangeTileCounts,
  [in]           UINT                                  Flags
);