typedef struct _WS_TCP_SSPI_KERBEROS_APREQ_POLICY_DESCRIPTION {
  WS_CHANNEL_PROPERTIES                                         channelProperties;
  WS_SECURITY_PROPERTIES                                        securityProperties;
  WS_SSPI_TRANSPORT_SECURITY_BINDING_POLICY_DESCRIPTION         sspiTransportSecurityBinding;
  WS_KERBEROS_APREQ_MESSAGE_SECURITY_BINDING_POLICY_DESCRIPTION kerberosApreqMessageSecurityBinding;
} WS_TCP_SSPI_KERBEROS_APREQ_POLICY_DESCRIPTION;