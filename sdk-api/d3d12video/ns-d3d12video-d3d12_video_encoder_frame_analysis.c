typedef struct D3D12_VIDEO_ENCODER_FRAME_ANALYSIS {
  ID3D12Resource                      *pDownscaledFrame;
  UINT64                              Subresource;
  D3D12_VIDEO_ENCODE_REFERENCE_FRAMES DownscaledReferences;
} D3D12_VIDEO_ENCODER_FRAME_ANALYSIS;