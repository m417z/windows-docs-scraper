typedef struct D3D12_VIDEO_ENCODE_REFERENCE_FRAMES {
  UINT           NumTexture2Ds;
  ID3D12Resource **ppTexture2Ds;
  UINT           *pSubresources;
} D3D12_VIDEO_ENCODE_REFERENCE_FRAMES;