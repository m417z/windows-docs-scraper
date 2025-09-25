void CopySubresourceRegion1(
  [in]           ID3D11Resource  *pDstResource,
  [in]           UINT            DstSubresource,
  [in]           UINT            DstX,
  [in]           UINT            DstY,
  [in]           UINT            DstZ,
  [in]           ID3D11Resource  *pSrcResource,
  [in]           UINT            SrcSubresource,
  [in, optional] const D3D11_BOX *pSrcBox,
  [in]           UINT            CopyFlags
);