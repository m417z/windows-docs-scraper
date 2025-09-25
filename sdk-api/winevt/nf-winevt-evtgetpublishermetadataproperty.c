BOOL EvtGetPublisherMetadataProperty(
  [in]  EVT_HANDLE                         PublisherMetadata,
  [in]  EVT_PUBLISHER_METADATA_PROPERTY_ID PropertyId,
  [in]  DWORD                              Flags,
  [in]  DWORD                              PublisherMetadataPropertyBufferSize,
  [in]  PEVT_VARIANT                       PublisherMetadataPropertyBuffer,
  [out] PDWORD                             PublisherMetadataPropertyBufferUsed
);