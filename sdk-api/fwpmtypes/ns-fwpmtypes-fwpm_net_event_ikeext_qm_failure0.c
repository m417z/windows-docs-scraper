typedef struct FWPM_NET_EVENT_IKEEXT_QM_FAILURE0_ {
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
} FWPM_NET_EVENT_IKEEXT_QM_FAILURE0;