void ReadFromSubresource(
  [out]          void            *pDstData,
  [in]           UINT            DstRowPitch,
  [in]           UINT            DstDepthPitch,
  [in]           ID3D11Resource  *pSrcResource,
  [in]           UINT            SrcSubresource,
  [in, optional] const D3D11_BOX *pSrcBox
);