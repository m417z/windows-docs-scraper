HRESULT CreateDecodeSwapChainForCompositionSurfaceHandle(
  [in]           IUnknown                    *pDevice,
  [in, optional] HANDLE                      hSurface,
  [in]           DXGI_DECODE_SWAP_CHAIN_DESC *pDesc,
  [in]           IDXGIResource               *pYuvDecodeBuffers,
  [in, optional] IDXGIOutput                 *pRestrictToOutput,
  [out]          IDXGIDecodeSwapChain        **ppSwapChain
);