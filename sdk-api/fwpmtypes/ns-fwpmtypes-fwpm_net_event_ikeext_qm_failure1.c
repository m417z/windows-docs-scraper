typedef struct FWPM_NET_EVENT_IKEEXT_QM_FAILURE1_ {
  UINT32                 failureErrorCode;
  IPSEC_FAILURE_POINT    failurePoint;
  IKEEXT_KEY_MODULE_TYPE keyingModuleType;
  IKEEXT_QM_SA_STATE     qmState;
  IKEEXT_SA_ROLE         saRole;
  IPSEC_TRAFFIC_TYPE     saTrafficType;
  union {
    FWP_CONDITION_VALUE0 localSubNet;
  };
  union {
    FWP_CONDITION_VALUE0 remoteSubNet;
  };
  UINT64                 qmFilterId;
  UINT64                 mmSaLuid;
  GUID                   mmProviderContextKey;
} FWPM_NET_EVENT_IKEEXT_QM_FAILURE1;