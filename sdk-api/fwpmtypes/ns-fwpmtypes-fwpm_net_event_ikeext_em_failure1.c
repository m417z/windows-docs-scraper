typedef struct FWPM_NET_EVENT_IKEEXT_EM_FAILURE1_ {
  UINT32                            failureErrorCode;
  IPSEC_FAILURE_POINT               failurePoint;
  UINT32                            flags;
  IKEEXT_EM_SA_STATE                emState;
  IKEEXT_SA_ROLE                    saRole;
  IKEEXT_AUTHENTICATION_METHOD_TYPE emAuthMethod;
  UINT8                             endCertHash[20];
  UINT64                            mmId;
  UINT64                            qmFilterId;
  wchar_t                           *localPrincipalNameForAuth;
  wchar_t                           *remotePrincipalNameForAuth;
  UINT32                            numLocalPrincipalGroupSids;
  LPWSTR                            *localPrincipalGroupSids;
  UINT32                            numRemotePrincipalGroupSids;
  LPWSTR                            *remotePrincipalGroupSids;
  IPSEC_TRAFFIC_TYPE                saTrafficType;
} FWPM_NET_EVENT_IKEEXT_EM_FAILURE1;