PFN_IDDCXSWAPCHAINSETDEVICE PfnIddcxswapchainsetdevice;

HRESULT * PfnIddcxswapchainsetdevice(
  [in] PIDD_DRIVER_GLOBALS DriverGlobals,
  [in] IDDCX_SWAPCHAIN SwapChainObject,
  [in] const IDARG_IN_SWAPCHAINSETDEVICE *pInArgs
)
{...}