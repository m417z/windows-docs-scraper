typedef struct IPSEC_TRANSPORT_POLICY2_ {
  UINT32                 numIpsecProposals;
  IPSEC_PROPOSAL0        *ipsecProposals;
  UINT32                 flags;
  UINT32                 ndAllowClearTimeoutSeconds;
  IPSEC_SA_IDLE_TIMEOUT0 saIdleTimeout;
  IKEEXT_EM_POLICY2      *emPolicy;
} IPSEC_TRANSPORT_POLICY2;