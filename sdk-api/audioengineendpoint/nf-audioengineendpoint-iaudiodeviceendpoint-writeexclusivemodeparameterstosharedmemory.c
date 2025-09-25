HRESULT WriteExclusiveModeParametersToSharedMemory(
  [in]  UINT_PTR hTargetProcess,
  [in]  HNSTIME  hnsPeriod,
  [in]  HNSTIME  hnsBufferDuration,
  [in]  UINT32   u32LatencyCoefficient,
  [out] UINT32   *pu32SharedMemorySize,
  [out] UINT_PTR *phSharedMemory
);