typedef struct _PNRPINFO_V1 {
  DWORD                    dwSize;
  LPWSTR                   lpwszIdentity;
  DWORD                    nMaxResolve;
  DWORD                    dwTimeout;
  DWORD                    dwLifetime;
  PNRP_RESOLVE_CRITERIA    enResolveCriteria;
  DWORD                    dwFlags;
  SOCKET_ADDRESS           saHint;
  PNRP_REGISTERED_ID_STATE enNameState;
} PNRPINFO_V1, *PPNRPINFO_V1;