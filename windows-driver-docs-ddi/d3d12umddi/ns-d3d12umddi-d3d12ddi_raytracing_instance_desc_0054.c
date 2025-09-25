typedef struct D3D12DDI_RAYTRACING_INSTANCE_DESC_0054 {
  FLOAT                        Transform[3][4];
  UINT                         InstanceID : 24;
  UINT                         InstanceMask : 8;
  UINT                         InstanceContributionToHitGroupIndex : 24;
  UINT                         Flags : 8;
  D3D12DDI_GPU_VIRTUAL_ADDRESS AccelerationStructure;
} D3D12DDI_RAYTRACING_INSTANCE_DESC_0054;