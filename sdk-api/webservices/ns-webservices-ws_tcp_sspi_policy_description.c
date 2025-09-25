typedef struct _WS_TCP_SSPI_POLICY_DESCRIPTION {
  WS_CHANNEL_PROPERTIES                                 channelProperties;
  WS_SECURITY_PROPERTIES                                securityProperties;
  WS_SSPI_TRANSPORT_SECURITY_BINDING_POLICY_DESCRIPTION sspiTransportSecurityBinding;
} WS_TCP_SSPI_POLICY_DESCRIPTION;