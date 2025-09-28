typedef enum _HTTP_REQUEST_INFO_TYPE {
  HttpRequestInfoTypeAuth,
  HttpRequestInfoTypeChannelBind,
  HttpRequestInfoTypeSslProtocol,
  HttpRequestInfoTypeSslTokenBindingDraft,
  HttpRequestInfoTypeSslTokenBinding,
  HttpRequestInfoTypeRequestTiming,
  HttpRequestInfoTypeTcpInfoV0,
  HttpRequestInfoTypeRequestSizing,
  HttpRequestInfoTypeQuicStats,
  HttpRequestInfoTypeTcpInfoV1,
  HttpRequestInfoTypeQuicStatsV2,
  HttpRequestInfoTypeTcpInfoV2,
  HttpRequestInfoTypeTransportIdleConnectionTimeout,
  HttpRequestInfoTypeDscpTag,
  HttpRequestInfoTypeInitialPacketTtl
} HTTP_REQUEST_INFO_TYPE, *PHTTP_REQUEST_INFO_TYPE;