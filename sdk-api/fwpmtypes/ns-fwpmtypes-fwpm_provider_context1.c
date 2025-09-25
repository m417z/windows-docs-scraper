typedef struct FWPM_PROVIDER_CONTEXT1_ {
  GUID                       providerContextKey;
  FWPM_DISPLAY_DATA0         displayData;
  UINT32                     flags;
  GUID                       *providerKey;
  FWP_BYTE_BLOB              providerData;
  FWPM_PROVIDER_CONTEXT_TYPE type;
  union {
    IPSEC_KEYING_POLICY0    *keyingPolicy;
    IPSEC_TRANSPORT_POLICY1 *ikeQmTransportPolicy;
    IPSEC_TUNNEL_POLICY1    *ikeQmTunnelPolicy;
    IPSEC_TRANSPORT_POLICY1 *authipQmTransportPolicy;
    IPSEC_TUNNEL_POLICY1    *authipQmTunnelPolicy;
    IKEEXT_POLICY1          *ikeMmPolicy;
    IKEEXT_POLICY1          *authIpMmPolicy;
    FWP_BYTE_BLOB           *dataBuffer;
    FWPM_CLASSIFY_OPTIONS0  *classifyOptions;
    IPSEC_TUNNEL_POLICY1    *ikeV2QmTunnelPolicy;
    IKEEXT_POLICY1          *ikeV2MmPolicy;
    IPSEC_DOSP_OPTIONS0     *idpOptions;
  };
  UINT64                     providerContextId;
} FWPM_PROVIDER_CONTEXT1;