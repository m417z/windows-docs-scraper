void UpdateSubresource(
  [in] ID3D10Resource  *pDstResource,
  [in] UINT            DstSubresource,
  [in] const D3D10_BOX *pDstBox,
  [in] const void      *pSrcData,
  [in] UINT            SrcRowPitch,
  [in] UINT            SrcDepthPitch
);