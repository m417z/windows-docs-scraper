typedef struct _TOKEN_STATISTICS {
  LUID                         TokenId;
  LUID                         AuthenticationId;
  LARGE_INTEGER                ExpirationTime;
  TOKEN_TYPE                   TokenType;
  SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
  DWORD                        DynamicCharged;
  DWORD                        DynamicAvailable;
  DWORD                        GroupCount;
  DWORD                        PrivilegeCount;
  LUID                         ModifiedId;
} TOKEN_STATISTICS, *PTOKEN_STATISTICS;