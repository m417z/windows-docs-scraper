typedef struct D3D12_VIDEO_PROCESS_INPUT_STREAM {
  ID3D12Resource                    *pTexture2D;
  UINT                              Subresource;
  D3D12_VIDEO_PROCESS_REFERENCE_SET ReferenceSet;
} D3D12_VIDEO_PROCESS_INPUT_STREAM;