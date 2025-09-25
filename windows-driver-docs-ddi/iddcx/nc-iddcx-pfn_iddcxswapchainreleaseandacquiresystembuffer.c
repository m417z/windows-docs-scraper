PFN_IDDCXSWAPCHAINRELEASEANDACQUIRESYSTEMBUFFER PfnIddcxswapchainreleaseandacquiresystembuffer;

HRESULT * PfnIddcxswapchainreleaseandacquiresystembuffer(
  [in]  PIDD_DRIVER_GLOBALS DriverGlobals,
  [in]  IDDCX_SWAPCHAIN SwapChainObject,
  [out] IDARG_OUT_RELEASEANDACQUIRESYSTEMBUFFER *pOutArgs
)
{...}