PFND3D12DDI_GETMIPPACKING Pfnd3d12ddiGetmippacking;

VOID Pfnd3d12ddiGetmippacking(
  D3D12DDI_HDEVICE hDevice,
  D3D12DDI_HRESOURCE hTiledResource,
  UINT *pNumPackedMips,
  UINT *pNumTilesForPackedMips
)
{...}