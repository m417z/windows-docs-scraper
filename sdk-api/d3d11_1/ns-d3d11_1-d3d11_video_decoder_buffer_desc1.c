typedef struct D3D11_VIDEO_DECODER_BUFFER_DESC1 {
  D3D11_VIDEO_DECODER_BUFFER_TYPE              BufferType;
  UINT                                         DataOffset;
  UINT                                         DataSize;
  void                                         *pIV;
  UINT                                         IVSize;
  D3D11_VIDEO_DECODER_SUB_SAMPLE_MAPPING_BLOCK *pSubSampleMappingBlock;
  UINT                                         SubSampleMappingCount;
} D3D11_VIDEO_DECODER_BUFFER_DESC1;