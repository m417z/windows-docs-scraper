PFND3DWDDM1_3DDI_COPYTILES Pfnd3dwddm13DdiCopytiles;

VOID Pfnd3dwddm13DdiCopytiles(
  D3D10DDI_HDEVICE hDevice,
  D3D10DDI_HRESOURCE hTiledResource,
  const D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE *pTileRegionStartCoord,
  const D3DWDDM1_3DDI_TILE_REGION_SIZE *pTileRegionSize,
  D3D10DDI_HRESOURCE hBuffer,
  UINT64 BufferStartOffsetInBytes,
  UINT Flags
)
{...}