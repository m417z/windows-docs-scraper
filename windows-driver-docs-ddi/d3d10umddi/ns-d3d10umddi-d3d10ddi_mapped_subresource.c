typedef struct D3D10DDI_MAPPED_SUBRESOURCE {
  [out] void *pData;
  [out] UINT RowPitch;
  [out] UINT DepthPitch;
} D3D10DDI_MAPPED_SUBRESOURCE;