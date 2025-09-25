typedef struct D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC {
  D3D12_GPU_VIRTUAL_ADDRESS                            DestAccelerationStructureData;
  D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS Inputs;
  D3D12_GPU_VIRTUAL_ADDRESS                            SourceAccelerationStructureData;
  D3D12_GPU_VIRTUAL_ADDRESS                            ScratchAccelerationStructureData;
} D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC;