void CopySubresourceRegion(
  [in] ID3D10Resource  *pDstResource,
  [in] UINT            DstSubresource,
  [in] UINT            DstX,
  [in] UINT            DstY,
  [in] UINT            DstZ,
  [in] ID3D10Resource  *pSrcResource,
  [in] UINT            SrcSubresource,
  [in] const D3D10_BOX *pSrcBox
);