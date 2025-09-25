PFN_IDDCXMONITORSETSRMLIST PfnIddcxmonitorsetsrmlist;

NTSTATUS * PfnIddcxmonitorsetsrmlist(
  [in] PIDD_DRIVER_GLOBALS DriverGlobals,
  [in] IDDCX_MONITOR MonitorObject,
  [in] const IDARG_IN_SETSRMLIST *pInArgs
)
{...}