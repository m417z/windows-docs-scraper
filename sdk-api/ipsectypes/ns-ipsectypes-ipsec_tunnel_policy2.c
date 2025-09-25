typedef struct IPSEC_TUNNEL_POLICY2_ {
  UINT32                  flags;
  UINT32                  numIpsecProposals;
  IPSEC_PROPOSAL0         *ipsecProposals;
  IPSEC_TUNNEL_ENDPOINTS2 tunnelEndpoints;
  IPSEC_SA_IDLE_TIMEOUT0  saIdleTimeout;
  IKEEXT_EM_POLICY2       *emPolicy;
  UINT32                  fwdPathSaLifetime;
} IPSEC_TUNNEL_POLICY2;