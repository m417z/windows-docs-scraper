PFN_IDDCXGETVERSION PfnIddcxgetversion;

NTSTATUS * PfnIddcxgetversion(
  [in]  PIDD_DRIVER_GLOBALS DriverGlobals,
  [out] IDARG_OUT_GETVERSION *pOutArgs
)
{...}