typedef struct D3D12DDIARG_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_0054 {
  D3D12DDI_GPU_VIRTUAL_ADDRESS                                              DestAccelerationStructureData;
  D3D12DDI_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS_0054              Inputs;
  D3D12DDI_GPU_VIRTUAL_ADDRESS                                              SourceAccelerationStructureData;
  D3D12DDI_GPU_VIRTUAL_ADDRESS                                              ScratchAccelerationStructureData;
  UINT                                                                      NumPostbuildInfoDescs;
  const D3D12DDI_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC_0054 *pPostbuildInfoDescs;
} D3D12DDIARG_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_0054;