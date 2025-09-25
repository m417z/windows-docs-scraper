typedef struct _WS_SERVICE_METADATA {
  ULONG                        documentCount;
  WS_SERVICE_METADATA_DOCUMENT **documents;
  WS_XML_STRING                *serviceName;
  WS_XML_STRING                *serviceNs;
} WS_SERVICE_METADATA;