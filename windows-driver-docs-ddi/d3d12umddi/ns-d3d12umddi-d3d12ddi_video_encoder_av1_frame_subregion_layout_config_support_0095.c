typedef struct D3D12DDI_VIDEO_ENCODER_AV1_FRAME_SUBREGION_LAYOUT_CONFIG_SUPPORT_0095 {
  BOOL                                                                           Use128SuperBlocks;
  D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_SUBREGIONS_LAYOUT_DATA_TILES_0095   TilesConfiguration;
  D3D12DDI_VIDEO_ENCODER_AV1_FRAME_SUBREGION_LAYOUT_CONFIG_VALIDATION_0095_FLAGS ValidationFlags;
  UINT                                                                           MinTileRows;
  UINT                                                                           MaxTileRows;
  UINT                                                                           MinTileCols;
  UINT                                                                           MaxTileCols;
  UINT                                                                           MinTileWidth;
  UINT                                                                           MaxTileWidth;
  UINT                                                                           MinTileArea;
  UINT                                                                           MaxTileArea;
  UINT                                                                           TileSizeBytesMinus1;
} D3D12DDI_VIDEO_ENCODER_AV1_FRAME_SUBREGION_LAYOUT_CONFIG_SUPPORT_0095;