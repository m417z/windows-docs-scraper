BOOL EvtGetEventMetadataProperty(
  [in]  EVT_HANDLE                     EventMetadata,
  [in]  EVT_EVENT_METADATA_PROPERTY_ID PropertyId,
  [in]  DWORD                          Flags,
  [in]  DWORD                          EventMetadataPropertyBufferSize,
  [in]  PEVT_VARIANT                   EventMetadataPropertyBuffer,
  [out] PDWORD                         EventMetadataPropertyBufferUsed
);