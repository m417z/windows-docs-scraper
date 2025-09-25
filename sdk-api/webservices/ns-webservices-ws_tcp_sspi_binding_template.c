typedef struct _WS_TCP_SSPI_BINDING_TEMPLATE {
  WS_CHANNEL_PROPERTIES                           channelProperties;
  WS_SECURITY_PROPERTIES                          securityProperties;
  WS_TCP_SSPI_TRANSPORT_SECURITY_BINDING_TEMPLATE sspiTransportSecurityBinding;
} WS_TCP_SSPI_BINDING_TEMPLATE;