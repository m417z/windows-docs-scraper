void OMSetRenderTargetsAndUnorderedAccessViews(
  [in]           UINT                      NumRTVs,
  [in, optional] ID3D11RenderTargetView    * const *ppRenderTargetViews,
  [in, optional] ID3D11DepthStencilView    *pDepthStencilView,
  [in]           UINT                      UAVStartSlot,
  [in]           UINT                      NumUAVs,
  [in, optional] ID3D11UnorderedAccessView * const *ppUnorderedAccessViews,
  [in, optional] const UINT                *pUAVInitialCounts
);