typedef struct _WS_HTTP_MESSAGE_MAPPING {
  ULONG                  requestMappingOptions;
  ULONG                  responseMappingOptions;
  WS_HTTP_HEADER_MAPPING **requestHeaderMappings;
  ULONG                  requestHeaderMappingCount;
  WS_HTTP_HEADER_MAPPING **responseHeaderMappings;
  ULONG                  responseHeaderMappingCount;
} WS_HTTP_MESSAGE_MAPPING;