typedef struct D3D12_VIDEO_PROCESS_REFERENCE_SET {
  UINT           NumPastFrames;
  ID3D12Resource **ppPastFrames;
  UINT           *pPastSubresources;
  UINT           NumFutureFrames;
  ID3D12Resource **ppFutureFrames;
  UINT           *pFutureSubresources;
} D3D12_VIDEO_PROCESS_REFERENCE_SET;