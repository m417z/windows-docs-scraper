typedef struct D3D12_FEATURE_DATA_D3D12_OPTIONS3 {
  BOOL                             CopyQueueTimestampQueriesSupported;
  BOOL                             CastingFullyTypedFormatSupported;
  D3D12_COMMAND_LIST_SUPPORT_FLAGS WriteBufferImmediateSupportFlags;
  D3D12_VIEW_INSTANCING_TIER       ViewInstancingTier;
  BOOL                             BarycentricsSupported;
} D3D12_FEATURE_DATA_D3D12_OPTIONS3;