typedef struct D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS {
  D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE        Type;
  D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS Flags;
  UINT                                                NumDescs;
  D3D12_ELEMENTS_LAYOUT                               DescsLayout;
  union {
    D3D12_GPU_VIRTUAL_ADDRESS                          InstanceDescs;
    const D3D12_RAYTRACING_GEOMETRY_DESC               *pGeometryDescs;
    const D3D12_RAYTRACING_GEOMETRY_DESC const *               * ppGeometryDescs;
    const D3D12_RAYTRACING_OPACITY_MICROMAP_ARRAY_DESC *pOpacityMicromapArrayDesc;
  };
} D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS;