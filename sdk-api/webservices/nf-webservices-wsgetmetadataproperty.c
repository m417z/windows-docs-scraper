HRESULT WsGetMetadataProperty(
  [in]           WS_METADATA             *metadata,
  [in]           WS_METADATA_PROPERTY_ID id,
                 void                    *value,
  [in]           ULONG                   valueSize,
  [in, optional] WS_ERROR                *error
);