typedef struct D3D12_FEATURE_DATA_VIDEO_PROCESS_SUPPORT {
  UINT                                      NodeIndex;
  D3D12_VIDEO_SAMPLE                        InputSample;
  D3D12_VIDEO_FIELD_TYPE                    InputFieldType;
  D3D12_VIDEO_FRAME_STEREO_FORMAT           InputStereoFormat;
  DXGI_RATIONAL                             InputFrameRate;
  D3D12_VIDEO_FORMAT                        OutputFormat;
  D3D12_VIDEO_FRAME_STEREO_FORMAT           OutputStereoFormat;
  DXGI_RATIONAL                             OutputFrameRate;
  D3D12_VIDEO_PROCESS_SUPPORT_FLAGS         SupportFlags;
  D3D12_VIDEO_SCALE_SUPPORT                 ScaleSupport;
  D3D12_VIDEO_PROCESS_FEATURE_FLAGS         FeatureSupport;
  D3D12_VIDEO_PROCESS_DEINTERLACE_FLAGS     DeinterlaceSupport;
  D3D12_VIDEO_PROCESS_AUTO_PROCESSING_FLAGS AutoProcessingSupport;
  D3D12_VIDEO_PROCESS_FILTER_FLAGS          FilterSupport;
  D3D12_VIDEO_PROCESS_FILTER_RANGE          FilterRangeSupport[32];
} D3D12_FEATURE_DATA_VIDEO_PROCESS_SUPPORT;