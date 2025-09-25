typedef struct FWPM_PROVIDER_CONTEXT3_ {
  GUID                       providerContextKey;
  FWPM_DISPLAY_DATA0         displayData;
  UINT32                     flags;
  GUID                       *providerKey;
  FWP_BYTE_BLOB              providerData;
  FWPM_PROVIDER_CONTEXT_TYPE type;
  union {
    IPSEC_KEYING_POLICY1                     *keyingPolicy;
    IPSEC_TRANSPORT_POLICY2                  *ikeQmTransportPolicy;
    IPSEC_TUNNEL_POLICY3                     *ikeQmTunnelPolicy;
    IPSEC_TRANSPORT_POLICY2                  *authipQmTransportPolicy;
    IPSEC_TUNNEL_POLICY3                     *authipQmTunnelPolicy;
    IKEEXT_POLICY2                           *ikeMmPolicy;
    IKEEXT_POLICY2                           *authIpMmPolicy;
    FWP_BYTE_BLOB                            *dataBuffer;
    FWPM_CLASSIFY_OPTIONS0                   *classifyOptions;
    IPSEC_TUNNEL_POLICY3                     *ikeV2QmTunnelPolicy;
    IPSEC_TRANSPORT_POLICY2                  *ikeV2QmTransportPolicy;
    IKEEXT_POLICY2                           *ikeV2MmPolicy;
    IPSEC_DOSP_OPTIONS0                      *idpOptions;
    FWPM_NETWORK_CONNECTION_POLICY_SETTINGS0 *networkConnectionPolicy;
  };
  UINT64                     providerContextId;
} FWPM_PROVIDER_CONTEXT3;