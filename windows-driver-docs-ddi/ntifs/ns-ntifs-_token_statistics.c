typedef struct _TOKEN_STATISTICS {
  LUID                         TokenId;
  LUID                         AuthenticationId;
  LARGE_INTEGER                ExpirationTime;
  TOKEN_TYPE                   TokenType;
  SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
  ULONG                        DynamicCharged;
  ULONG                        DynamicAvailable;
  ULONG                        GroupCount;
  ULONG                        PrivilegeCount;
  LUID                         ModifiedId;
} TOKEN_STATISTICS, *PTOKEN_STATISTICS;