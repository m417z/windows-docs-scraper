PFN_IDDCXADAPTERDISPLAYCONFIGUPDATE PfnIddcxadapterdisplayconfigupdate;

NTSTATUS * PfnIddcxadapterdisplayconfigupdate(
  [in] PIDD_DRIVER_GLOBALS DriverGlobals,
  [in] IDDCX_ADAPTER AdapterObject,
  [in] const IDARG_IN_ADAPTERDISPLAYCONFIGUPDATE *pInArgs
)
{...}