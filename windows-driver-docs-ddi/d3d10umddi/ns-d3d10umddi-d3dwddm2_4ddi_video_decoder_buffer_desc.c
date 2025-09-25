typedef struct D3DWDDM2_4DDI_VIDEO_DECODER_BUFFER_DESC {
  D3D10DDI_HRESOURCE                                   hResource;
  D3D11_1DDI_VIDEO_DECODER_BUFFER_TYPE                 BufferType;
  UINT                                                 DataOffset;
  UINT                                                 DataSize;
  void                                                 *pIV;
  UINT                                                 IVSize;
  D3DWDDM2_0DDI_VIDEO_DECODER_SUB_SAMPLE_MAPPING_BLOCK *pSubSampleMappingBlock;
  UINT                                                 SubSampleMappingCount;
  UINT                                                 cBlocksStripeEncrypted;
  UINT                                                 cBlocksStripeClear;
} D3DWDDM2_4DDI_VIDEO_DECODER_BUFFER_DESC;