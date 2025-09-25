HRESULT CreateSwapChainForHwnd(
  [in]           IUnknown                              *pDevice,
  [in]           HWND                                  hWnd,
  [in]           const DXGI_SWAP_CHAIN_DESC1           *pDesc,
  [in, optional] const DXGI_SWAP_CHAIN_FULLSCREEN_DESC *pFullscreenDesc,
  [in, optional] IDXGIOutput                           *pRestrictToOutput,
  [out]          IDXGISwapChain1                       **ppSwapChain
);