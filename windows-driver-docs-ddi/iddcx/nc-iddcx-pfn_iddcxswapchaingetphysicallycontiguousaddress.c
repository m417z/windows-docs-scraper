PFN_IDDCXSWAPCHAINGETPHYSICALLYCONTIGUOUSADDRESS PfnIddcxswapchaingetphysicallycontiguousaddress;

HRESULT * PfnIddcxswapchaingetphysicallycontiguousaddress(
  [in]  PIDD_DRIVER_GLOBALS DriverGlobals,
  [in]  IDDCX_SWAPCHAIN SwapChainObject,
  [out] PHYSICAL_ADDRESS *pSurfaceAddresss
)
{...}