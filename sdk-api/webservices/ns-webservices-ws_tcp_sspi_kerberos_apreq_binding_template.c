typedef struct _WS_TCP_SSPI_KERBEROS_APREQ_BINDING_TEMPLATE {
  WS_CHANNEL_PROPERTIES                               channelProperties;
  WS_SECURITY_PROPERTIES                              securityProperties;
  WS_TCP_SSPI_TRANSPORT_SECURITY_BINDING_TEMPLATE     sspiTransportSecurityBinding;
  WS_KERBEROS_APREQ_MESSAGE_SECURITY_BINDING_TEMPLATE kerberosApreqMessageSecurityBinding;
} WS_TCP_SSPI_KERBEROS_APREQ_BINDING_TEMPLATE;