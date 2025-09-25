typedef struct IPSEC_SA_BUNDLE0_ {
  UINT32                 flags;
  IPSEC_SA_LIFETIME0     lifetime;
  UINT32                 idleTimeoutSeconds;
  UINT32                 ndAllowClearTimeoutSeconds;
  IPSEC_ID0              *ipsecId;
  UINT32                 napContext;
  UINT32                 qmSaId;
  UINT32                 numSAs;
  IPSEC_SA0              *saList;
  IPSEC_KEYMODULE_STATE0 *keyModuleState;
  FWP_IP_VERSION         ipVersion;
  union {
    UINT32 peerV4PrivateAddress;
  };
  UINT64                 mmSaId;
  IPSEC_PFS_GROUP        pfsGroup;
} IPSEC_SA_BUNDLE0;