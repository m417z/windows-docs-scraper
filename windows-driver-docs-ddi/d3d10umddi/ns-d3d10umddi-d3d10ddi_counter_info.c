typedef struct D3D10DDI_COUNTER_INFO {
  [out] D3D10DDI_QUERY LastDeviceDependentCounter;
  [out] UINT           NumSimultaneousCounters;
  [out] UINT8          NumDetectableParallelUnits;
} D3D10DDI_COUNTER_INFO;