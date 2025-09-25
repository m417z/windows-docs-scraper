typedef struct FWPM_PROVIDER_CONTEXT0_ {
  GUID                       providerContextKey;
  FWPM_DISPLAY_DATA0         displayData;
  UINT32                     flags;
  GUID                       *providerKey;
  FWP_BYTE_BLOB              providerData;
  FWPM_PROVIDER_CONTEXT_TYPE type;
  union {
    IPSEC_KEYING_POLICY0    *keyingPolicy;
    IPSEC_TRANSPORT_POLICY0 *ikeQmTransportPolicy;
    IPSEC_TUNNEL_POLICY0    *ikeQmTunnelPolicy;
    IPSEC_TRANSPORT_POLICY0 *authipQmTransportPolicy;
    IPSEC_TUNNEL_POLICY0    *authipQmTunnelPolicy;
    IKEEXT_POLICY0          *ikeMmPolicy;
    IKEEXT_POLICY0          *authIpMmPolicy;
    FWP_BYTE_BLOB           *dataBuffer;
    FWPM_CLASSIFY_OPTIONS0  *classifyOptions;
  };
  UINT64                     providerContextId;
} FWPM_PROVIDER_CONTEXT0;