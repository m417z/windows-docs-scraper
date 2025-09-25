PFN_IDDCXSWAPCHAININSYSTEMMEMORY PfnIddcxswapchaininsystemmemory;

HRESULT * PfnIddcxswapchaininsystemmemory(
  [in]  PIDD_DRIVER_GLOBALS DriverGlobals,
  [in]  IDDCX_SWAPCHAIN SwapChainObject,
  [out] BOOL *pInSystemMemory
)
{...}