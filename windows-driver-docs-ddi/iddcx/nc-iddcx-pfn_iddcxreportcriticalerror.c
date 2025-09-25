PFN_IDDCXREPORTCRITICALERROR PfnIddcxreportcriticalerror;

NTSTATUS * PfnIddcxreportcriticalerror(
  [in]      PIDD_DRIVER_GLOBALS DriverGlobals,
  [in, opt] IDDCX_ADAPTER AdapterObject,
  [in]      const IDARG_IN_REPORTCRITICALERROR *pInArgs
)
{...}