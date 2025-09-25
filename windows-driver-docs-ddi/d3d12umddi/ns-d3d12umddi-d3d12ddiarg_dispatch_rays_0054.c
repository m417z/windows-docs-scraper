typedef struct D3D12DDIARG_DISPATCH_RAYS_0054 {
  D3D12DDI_GPU_VIRTUAL_ADDRESS_RANGE            RayGenerationShaderRecord;
  D3D12DDI_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE MissShaderTable;
  D3D12DDI_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE HitGroupTable;
  D3D12DDI_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE CallableShaderTable;
  UINT                                          Width;
  UINT                                          Height;
  UINT                                          Depth;
} D3D12DDIARG_DISPATCH_RAYS_0054;