typedef struct _WS_HTTP_SSL_USERNAME_BINDING_TEMPLATE {
  WS_CHANNEL_PROPERTIES                         channelProperties;
  WS_SECURITY_PROPERTIES                        securityProperties;
  WS_SSL_TRANSPORT_SECURITY_BINDING_TEMPLATE    sslTransportSecurityBinding;
  WS_USERNAME_MESSAGE_SECURITY_BINDING_TEMPLATE usernameMessageSecurityBinding;
} WS_HTTP_SSL_USERNAME_BINDING_TEMPLATE;