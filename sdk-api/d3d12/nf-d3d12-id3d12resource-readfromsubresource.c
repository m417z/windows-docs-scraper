HRESULT ReadFromSubresource(
  [out]          void            *pDstData,
                 UINT            DstRowPitch,
                 UINT            DstDepthPitch,
                 UINT            SrcSubresource,
  [in, optional] const D3D12_BOX *pSrcBox
);