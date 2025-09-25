typedef struct _AUTHZ_ACCESS_REPLY {
  DWORD        ResultListLength;
  PACCESS_MASK GrantedAccessMask;
  PDWORD       SaclEvaluationResults;
  PDWORD       Error;
} AUTHZ_ACCESS_REPLY, *PAUTHZ_ACCESS_REPLY;