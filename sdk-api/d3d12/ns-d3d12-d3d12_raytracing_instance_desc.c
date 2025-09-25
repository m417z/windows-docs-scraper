typedef struct D3D12_RAYTRACING_INSTANCE_DESC {
  FLOAT                     Transform[3][4];
  UINT                      InstanceID : 24;
  UINT                      InstanceMask : 8;
  UINT                      InstanceContributionToHitGroupIndex : 24;
  UINT                      Flags : 8;
  D3D12_GPU_VIRTUAL_ADDRESS AccelerationStructure;
} D3D12_RAYTRACING_INSTANCE_DESC;