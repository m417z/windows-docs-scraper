typedef struct _HTTP_CHANNEL_BIND_INFO {
  HTTP_AUTHENTICATION_HARDENING_LEVELS Hardening;
  ULONG                                Flags;
  PHTTP_SERVICE_BINDING_BASE           *ServiceNames;
  ULONG                                NumberOfServiceNames;
} HTTP_CHANNEL_BIND_INFO, *PHTTP_CHANNEL_BIND_INFO;