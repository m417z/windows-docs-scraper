typedef struct FWPM_NET_EVENT_IKEEXT_MM_FAILURE0_ {
  UINT32                            failureErrorCode;
  IPSEC_FAILURE_POINT               failurePoint;
  UINT32                            flags;
  IKEEXT_KEY_MODULE_TYPE            keyingModuleType;
  IKEEXT_MM_SA_STATE                mmState;
  IKEEXT_SA_ROLE                    saRole;
  IKEEXT_AUTHENTICATION_METHOD_TYPE mmAuthMethod;
  UINT8                             endCertHash[20];
  UINT64                            mmId;
  UINT64                            mmFilterId;
} FWPM_NET_EVENT_IKEEXT_MM_FAILURE0;