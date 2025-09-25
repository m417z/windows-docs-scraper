typedef struct _PNRPINFO_V2 {
  DWORD                      dwSize;
  LPWSTR                     lpwszIdentity;
  DWORD                      nMaxResolve;
  DWORD                      dwTimeout;
  DWORD                      dwLifetime;
  PNRP_RESOLVE_CRITERIA      enResolveCriteria;
  DWORD                      dwFlags;
  SOCKET_ADDRESS             saHint;
  PNRP_REGISTERED_ID_STATE   enNameState;
  PNRP_EXTENDED_PAYLOAD_TYPE enExtendedPayloadType;
  union {
    BLOB  blobPayload;
    PWSTR pwszPayload;
  };
} PNRPINFO_V2, *PPNRPINFO_V2;