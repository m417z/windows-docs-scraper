void OMSetRenderTargets(
  [in]           UINT                              NumRenderTargetDescriptors,
  [in, optional] const D3D12_CPU_DESCRIPTOR_HANDLE *pRenderTargetDescriptors,
  [in]           BOOL                              RTsSingleHandleToDescriptorRange,
  [in, optional] const D3D12_CPU_DESCRIPTOR_HANDLE *pDepthStencilDescriptor
);