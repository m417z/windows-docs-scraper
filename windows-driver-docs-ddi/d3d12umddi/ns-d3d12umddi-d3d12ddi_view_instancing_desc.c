typedef struct D3D12DDI_VIEW_INSTANCING_DESC {
  UINT                                  ViewInstanceCount;
  const D3D12DDI_VIEW_INSTANCE_LOCATION *pViewInstanceLocations;
  D3D12DDI_VIEW_INSTANCING_FLAGS        Flags;
} D3D12DDI_VIEW_INSTANCING_DESC;