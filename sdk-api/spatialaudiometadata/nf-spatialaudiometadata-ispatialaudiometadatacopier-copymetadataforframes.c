HRESULT CopyMetadataForFrames(
  [in]  UINT16                       copyFrameCount,
  [in]  SpatialAudioMetadataCopyMode copyMode,
  [in]  ISpatialAudioMetadataItems   *dstMetadataItems,
  [out] UINT16                       *itemsCopied
);