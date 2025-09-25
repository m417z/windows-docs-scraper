BOOL EvtGetChannelConfigProperty(
  [in]  EVT_HANDLE                     ChannelConfig,
  [in]  EVT_CHANNEL_CONFIG_PROPERTY_ID PropertyId,
  [in]  DWORD                          Flags,
  [in]  DWORD                          PropertyValueBufferSize,
  [in]  PEVT_VARIANT                   PropertyValueBuffer,
  [out] PDWORD                         PropertyValueBufferUsed
);