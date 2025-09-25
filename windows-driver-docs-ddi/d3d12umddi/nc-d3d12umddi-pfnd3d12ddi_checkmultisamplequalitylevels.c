PFND3D12DDI_CHECKMULTISAMPLEQUALITYLEVELS Pfnd3d12ddiCheckmultisamplequalitylevels;

VOID Pfnd3d12ddiCheckmultisamplequalitylevels(
  D3D12DDI_HDEVICE hDevice,
  DXGI_FORMAT Format,
  UINT SampleCount,
  D3D12DDI_MULTISAMPLE_QUALITY_LEVEL_FLAGS Flags,
  UINT *pNumQualityLevels
)
{...}