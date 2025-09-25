PFND3DWDDM1_3DDI_COPYTILEMAPPINGS Pfnd3dwddm13DdiCopytilemappings;

VOID Pfnd3dwddm13DdiCopytilemappings(
  D3D10DDI_HDEVICE hDevice,
  D3D10DDI_HRESOURCE hDestTiledResource,
  const D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE *pDestRegionStartCoord,
  D3D10DDI_HRESOURCE hSourceTiledResource,
  const D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE *pSourceRegionStartCoord,
  const D3DWDDM1_3DDI_TILE_REGION_SIZE *pTileRegionSize,
  UINT Flags
)
{...}