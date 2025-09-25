typedef struct D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS {
  ID3D12Resource                                                       *pSrcResource;
  ID3D12Resource                                                       *pDstResource;
  UINT                                                                 SubresourceCount;
  const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS *pSubresourceParameters;
  DXGI_FORMAT                                                          Format;
  D3D12_RESOLVE_MODE                                                   ResolveMode;
  BOOL                                                                 PreserveResolveSource;
} D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS;