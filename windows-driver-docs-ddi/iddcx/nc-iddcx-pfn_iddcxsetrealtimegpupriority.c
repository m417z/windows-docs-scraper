PFN_IDDCXSETREALTIMEGPUPRIORITY PfnIddcxsetrealtimegpupriority;

HRESULT * PfnIddcxsetrealtimegpupriority(
  [in] PIDD_DRIVER_GLOBALS DriverGlobals,
  [in] IDDCX_SWAPCHAIN SwapChainObject,
  [in] const IDARG_IN_SETREALTIMEGPUPRIORITY *pIn
)
{...}