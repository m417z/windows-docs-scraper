typedef struct IPSEC_TUNNEL_POLICY1_ {
  UINT32                  flags;
  UINT32                  numIpsecProposals;
  IPSEC_PROPOSAL0         *ipsecProposals;
  IPSEC_TUNNEL_ENDPOINTS1 tunnelEndpoints;
  IPSEC_SA_IDLE_TIMEOUT0  saIdleTimeout;
  IKEEXT_EM_POLICY1       *emPolicy;
} IPSEC_TUNNEL_POLICY1;