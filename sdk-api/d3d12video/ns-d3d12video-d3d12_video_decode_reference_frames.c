typedef struct D3D12_VIDEO_DECODE_REFERENCE_FRAMES {
  UINT                   NumTexture2Ds;
  ID3D12Resource         **ppTexture2Ds;
  UINT                   *pSubresources;
  ID3D12VideoDecoderHeap **ppHeaps;
} D3D12_VIDEO_DECODE_REFERENCE_FRAMES;