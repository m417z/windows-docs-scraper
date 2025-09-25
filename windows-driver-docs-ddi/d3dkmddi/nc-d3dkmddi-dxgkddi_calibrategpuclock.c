DXGKDDI_CALIBRATEGPUCLOCK DxgkddiCalibrategpuclock;

NTSTATUS DxgkddiCalibrategpuclock(
  IN_CONST_HANDLE hAdapter,
  IN UINT32 NodeOrdinal,
  IN UINT32 EngineOrdinal,
  OUT_PDXGKARG_CALIBRATEGPUCLOCK pClockCalibration
)
{...}