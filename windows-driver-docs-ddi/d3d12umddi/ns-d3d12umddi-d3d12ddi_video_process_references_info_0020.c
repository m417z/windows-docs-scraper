typedef struct D3D12DDI_VIDEO_PROCESS_REFERENCES_INFO_0020 {
  UINT               NumPastFrames;
  D3D12DDI_HRESOURCE *hDrvPastFrames;
  UINT               *pPastSubresources;
  UINT               NumFutureFrames;
  D3D12DDI_HRESOURCE *hDrvFutureFrames;
  UINT               *pFutureSubresources;
} D3D12DDI_VIDEO_PROCESS_REFERENCES_INFO_0020;