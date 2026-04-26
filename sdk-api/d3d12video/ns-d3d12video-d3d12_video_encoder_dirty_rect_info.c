typedef struct D3D12_VIDEO_ENCODER_DIRTY_RECT_INFO {
  BOOL                                              FullFrameIdentical;
  D3D12_VIDEO_ENCODER_DIRTY_REGIONS_MAP_VALUES_MODE MapValuesType;
  UINT                                              NumDirtyRects;
  RECT                                              *pDirtyRects;
  UINT                                              SourceDPBFrameReference;
} D3D12_VIDEO_ENCODER_DIRTY_RECT_INFO;