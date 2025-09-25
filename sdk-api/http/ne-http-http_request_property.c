typedef enum _HTTP_REQUEST_PROPERTY {
  HttpRequestPropertyIsb,
  HttpRequestPropertyTcpInfoV0,
  HttpRequestPropertyQuicStats,
  HttpRequestPropertyTcpInfoV1,
  HttpRequestPropertySni,
  HttpRequestPropertyStreamError,
  HttpRequestPropertyWskApiTimings,
  HttpRequestPropertyQuicApiTimings,
  HttpRequestPropertyQuicStatsV2,
  HttpRequestPropertyQuicStreamStats,
  HttpRequestPropertyTcpInfoV2,
  HttpRequestPropertyTlsClientHello,
  HttpRequestPropertyTransportIdleConnectionTimeout,
  HttpRequestPropertyDscpTag,
  HttpRequestPropertyTlsCipherInfo
} HTTP_REQUEST_PROPERTY, *PHTTP_REQUEST_PROPERTY;