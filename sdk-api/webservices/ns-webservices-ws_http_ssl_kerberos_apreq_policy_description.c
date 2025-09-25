typedef struct _WS_HTTP_SSL_KERBEROS_APREQ_POLICY_DESCRIPTION {
  WS_CHANNEL_PROPERTIES                                         channelProperties;
  WS_SECURITY_PROPERTIES                                        securityProperties;
  WS_SSL_TRANSPORT_SECURITY_BINDING_POLICY_DESCRIPTION          sslTransportSecurityBinding;
  WS_KERBEROS_APREQ_MESSAGE_SECURITY_BINDING_POLICY_DESCRIPTION kerberosApreqMessageSecurityBinding;
} WS_HTTP_SSL_KERBEROS_APREQ_POLICY_DESCRIPTION;