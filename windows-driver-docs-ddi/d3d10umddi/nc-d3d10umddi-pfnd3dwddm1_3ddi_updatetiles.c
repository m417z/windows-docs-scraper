PFND3DWDDM1_3DDI_UPDATETILES Pfnd3dwddm13DdiUpdatetiles;

VOID Pfnd3dwddm13DdiUpdatetiles(
  D3D10DDI_HDEVICE hDevice,
  D3D10DDI_HRESOURCE hDestTiledResource,
  const D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE *pDestTileRegionStartCoord,
  const D3DWDDM1_3DDI_TILE_REGION_SIZE *pDestTileRegionSize,
  const VOID *pSourceTileData,
  UINT Flags
)
{...}