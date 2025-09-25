typedef struct FWPM_NET_EVENT_IKEEXT_EM_FAILURE0_ {
  UINT32                            failureErrorCode;
  IPSEC_FAILURE_POINT               failurePoint;
  UINT32                            flags;
  IKEEXT_EM_SA_STATE                emState;
  IKEEXT_SA_ROLE                    saRole;
  IKEEXT_AUTHENTICATION_METHOD_TYPE emAuthMethod;
  UINT8                             endCertHash[20];
  UINT64                            mmId;
  UINT64                            qmFilterId;
} FWPM_NET_EVENT_IKEEXT_EM_FAILURE0;