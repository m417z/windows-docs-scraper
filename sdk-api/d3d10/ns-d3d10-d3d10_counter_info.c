typedef struct D3D10_COUNTER_INFO {
  D3D10_COUNTER LastDeviceDependentCounter;
  UINT          NumSimultaneousCounters;
  UINT8         NumDetectableParallelUnits;
} D3D10_COUNTER_INFO;