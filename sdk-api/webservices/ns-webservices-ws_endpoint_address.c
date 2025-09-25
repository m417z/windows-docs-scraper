typedef struct _WS_ENDPOINT_ADDRESS {
  WS_STRING            url;
  WS_XML_BUFFER        *headers;
  WS_XML_BUFFER        *extensions;
  WS_ENDPOINT_IDENTITY *identity;
} WS_ENDPOINT_ADDRESS;