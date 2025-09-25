void UpdateSubresource1(
  [in]           ID3D11Resource  *pDstResource,
  [in]           UINT            DstSubresource,
  [in, optional] const D3D11_BOX *pDstBox,
  [in]           const void      *pSrcData,
  [in]           UINT            SrcRowPitch,
  [in]           UINT            SrcDepthPitch,
  [in]           UINT            CopyFlags
);