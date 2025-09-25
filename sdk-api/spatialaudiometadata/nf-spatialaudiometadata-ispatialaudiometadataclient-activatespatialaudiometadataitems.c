HRESULT ActivateSpatialAudioMetadataItems(
  [in]            UINT16                           maxItemCount,
  [in]            UINT16                           frameCount,
  [out, optional] ISpatialAudioMetadataItemsBuffer **metadataItemsBuffer,
  [out]           ISpatialAudioMetadataItems       **metadataItems
);