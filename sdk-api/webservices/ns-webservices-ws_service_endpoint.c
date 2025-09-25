typedef struct _WS_SERVICE_ENDPOINT {
  WS_ENDPOINT_ADDRESS                address;
  WS_CHANNEL_BINDING                 channelBinding;
  WS_CHANNEL_TYPE                    channelType;
  const WS_SECURITY_DESCRIPTION      *securityDescription;
  const WS_SERVICE_CONTRACT          *contract;
  WS_SERVICE_SECURITY_CALLBACK       authorizationCallback;
  const WS_SERVICE_ENDPOINT_PROPERTY *properties;
  ULONG                              propertyCount;
  WS_CHANNEL_PROPERTIES              channelProperties;
} WS_SERVICE_ENDPOINT;