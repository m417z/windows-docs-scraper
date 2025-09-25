HRESULT CreateSwapChainForCompositionSurfaceHandle(
  [in]           IUnknown                    *pDevice,
  [in, optional] HANDLE                      hSurface,
  [in]           const DXGI_SWAP_CHAIN_DESC1 *pDesc,
  [in, optional] IDXGIOutput                 *pRestrictToOutput,
  [out]          IDXGISwapChain1             **ppSwapChain
);