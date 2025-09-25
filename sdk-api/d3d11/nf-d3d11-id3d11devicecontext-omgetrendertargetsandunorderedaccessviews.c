void OMGetRenderTargetsAndUnorderedAccessViews(
  [in]            UINT                      NumRTVs,
  [out, optional] ID3D11RenderTargetView    **ppRenderTargetViews,
  [out, optional] ID3D11DepthStencilView    **ppDepthStencilView,
  [in]            UINT                      UAVStartSlot,
  [in]            UINT                      NumUAVs,
  [out, optional] ID3D11UnorderedAccessView **ppUnorderedAccessViews
);