typedef struct _WS_TCP_SSPI_USERNAME_BINDING_TEMPLATE {
  WS_CHANNEL_PROPERTIES                           channelProperties;
  WS_SECURITY_PROPERTIES                          securityProperties;
  WS_TCP_SSPI_TRANSPORT_SECURITY_BINDING_TEMPLATE sspiTransportSecurityBinding;
  WS_USERNAME_MESSAGE_SECURITY_BINDING_TEMPLATE   usernameMessageSecurityBinding;
} WS_TCP_SSPI_USERNAME_BINDING_TEMPLATE;