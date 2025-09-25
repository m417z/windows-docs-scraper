typedef struct D3D12_VIEW_INSTANCING_DESC {
  UINT                               ViewInstanceCount;
  const D3D12_VIEW_INSTANCE_LOCATION *pViewInstanceLocations;
  D3D12_VIEW_INSTANCING_FLAGS        Flags;
} D3D12_VIEW_INSTANCING_DESC;