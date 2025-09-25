PFND3DWDDM1_3DDI_UPDATETILEMAPPINGS Pfnd3dwddm13DdiUpdatetilemappings;

VOID Pfnd3dwddm13DdiUpdatetilemappings(
  D3D10DDI_HDEVICE hDevice,
  D3D10DDI_HRESOURCE hTiledResource,
  UINT NumTiledResourceRegions,
  const D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE *pTiledResourceRegionStartCoords,
  const D3DWDDM1_3DDI_TILE_REGION_SIZE *pTiledResourceRegionSizes,
  D3D10DDI_HRESOURCE hTilePool,
  UINT NumRanges,
  const UINT *pRangeFlags,
  const UINT *pTilePoolStartOffsets,
  const UINT *pRangeTileCounts,
  UINT Flags
)
{...}