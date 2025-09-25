void ResolveSubresourceRegion(
  [in]           ID3D12Resource     *pDstResource,
  [in]           UINT               DstSubresource,
  [in]           UINT               DstX,
  [in]           UINT               DstY,
  [in]           ID3D12Resource     *pSrcResource,
  [in]           UINT               SrcSubresource,
  [in, optional] D3D12_RECT         *pSrcRect,
  [in]           DXGI_FORMAT        Format,
  [in]           D3D12_RESOLVE_MODE ResolveMode
);