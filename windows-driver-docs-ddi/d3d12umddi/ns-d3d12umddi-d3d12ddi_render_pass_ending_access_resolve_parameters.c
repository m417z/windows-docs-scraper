typedef struct D3D12DDI_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS {
  D3D12DDI_HRESOURCE                                                      hSrcResource;
  D3D12DDI_HRESOURCE                                                      hDstResource;
  UINT                                                                    SubresourceCount;
  const D3D12DDI_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS *pSubresourceParameters;
  DXGI_FORMAT                                                             Format;
  D3D12DDI_RESOLVE_MODE                                                   ResolveMode;
} D3D12DDI_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS;