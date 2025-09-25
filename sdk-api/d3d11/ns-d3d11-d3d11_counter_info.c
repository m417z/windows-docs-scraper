typedef struct D3D11_COUNTER_INFO {
  D3D11_COUNTER LastDeviceDependentCounter;
  UINT          NumSimultaneousCounters;
  UINT8         NumDetectableParallelUnits;
} D3D11_COUNTER_INFO;