typedef struct _WS_METADATA_ENDPOINT {
  WS_ENDPOINT_ADDRESS endpointAddress;
  WS_POLICY           *endpointPolicy;
  WS_XML_STRING       *portName;
  WS_XML_STRING       *serviceName;
  WS_XML_STRING       *serviceNs;
  WS_XML_STRING       *bindingName;
  WS_XML_STRING       *bindingNs;
  WS_XML_STRING       *portTypeName;
  WS_XML_STRING       *portTypeNs;
} WS_METADATA_ENDPOINT;