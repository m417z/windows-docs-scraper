void VideoProcessorSetStreamHDRMetaData(
  [in] ID3D11VideoProcessor   *pVideoProcessor,
  [in] UINT                   StreamIndex,
  [in] DXGI_HDR_METADATA_TYPE Type,
  [in] UINT                   Size,
  [in] const void             *pHDRMetaData
);