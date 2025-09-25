HRESULT WriteToSubresource(
                 UINT            DstSubresource,
  [in, optional] const D3D12_BOX *pDstBox,
  [in]           const void      *pSrcData,
                 UINT            SrcRowPitch,
                 UINT            SrcDepthPitch
);