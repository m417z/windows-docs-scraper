void CopyTextureRegion(
  [in]           const D3D12_TEXTURE_COPY_LOCATION *pDst,
                 UINT                              DstX,
                 UINT                              DstY,
                 UINT                              DstZ,
  [in]           const D3D12_TEXTURE_COPY_LOCATION *pSrc,
  [in, optional] const D3D12_BOX                   *pSrcBox
);