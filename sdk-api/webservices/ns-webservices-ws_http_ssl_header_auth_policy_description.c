typedef struct _WS_HTTP_SSL_HEADER_AUTH_POLICY_DESCRIPTION {
  WS_CHANNEL_PROPERTIES                                   channelProperties;
  WS_SECURITY_PROPERTIES                                  securityProperties;
  WS_SSL_TRANSPORT_SECURITY_BINDING_POLICY_DESCRIPTION    sslTransportSecurityBinding;
  WS_HTTP_HEADER_AUTH_SECURITY_BINDING_POLICY_DESCRIPTION httpHeaderAuthSecurityBinding;
} WS_HTTP_SSL_HEADER_AUTH_POLICY_DESCRIPTION;