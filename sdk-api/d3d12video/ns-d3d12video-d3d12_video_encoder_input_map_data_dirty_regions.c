typedef struct D3D12_VIDEO_ENCODER_INPUT_MAP_DATA_DIRTY_REGIONS {
  BOOL                                              FullFrameIdentical;
  D3D12_VIDEO_ENCODER_DIRTY_REGIONS_MAP_VALUES_MODE MapValuesType;
  ID3D12Resource                                    *pDirtyRegionsMap;
  UINT                                              SourceDPBFrameReference;
} D3D12_VIDEO_ENCODER_INPUT_MAP_DATA_DIRTY_REGIONS;