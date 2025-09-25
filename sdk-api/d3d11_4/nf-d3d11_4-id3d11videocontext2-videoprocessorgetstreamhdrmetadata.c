void VideoProcessorGetStreamHDRMetaData(
  [in]  ID3D11VideoProcessor   *pVideoProcessor,
  [in]  UINT                   StreamIndex,
  [out] DXGI_HDR_METADATA_TYPE *pType,
  [in]  UINT                   Size,
  [out] void                   *pMetaData
);