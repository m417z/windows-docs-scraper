PFN_IDDCXMONITORGETSRMLISTVERSION PfnIddcxmonitorgetsrmlistversion;

NTSTATUS * PfnIddcxmonitorgetsrmlistversion(
  [in]  PIDD_DRIVER_GLOBALS DriverGlobals,
  [in]  IDDCX_MONITOR MonitorObject,
  [in]  const IDARG_IN_GETSRMLISTVERSION *pInArgs,
  [out] IDARG_OUT_GETSRMLISTVERSION *pOutArgs
)
{...}