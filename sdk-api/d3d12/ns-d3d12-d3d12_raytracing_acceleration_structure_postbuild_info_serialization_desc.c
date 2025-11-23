typedef struct D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC {
  UINT64 SerializedSizeInBytes;
  union {
    UINT64 NumBottomLevelAccelerationStructurePointers;
    UINT64 NumBottomLevelAccelerationStructureHeaderAndPointerListPairs;
  };
} D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC;