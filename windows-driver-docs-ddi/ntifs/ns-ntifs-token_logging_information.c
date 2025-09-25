typedef struct _TOKEN_LOGGING_INFORMATION {
  TOKEN_TYPE                   TokenType;
  TOKEN_ELEVATION              TokenElevation;
  TOKEN_ELEVATION_TYPE         TokenElevationType;
  SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
  ULONG                        IntegrityLevel;
  SID_AND_ATTRIBUTES           User;
  PSID                         TrustLevelSid;
  ULONG                        SessionId;
  ULONG                        AppContainerNumber;
  LUID                         AuthenticationId;
  ULONG                        GroupCount;
  ULONG                        GroupsLength;
  PSID_AND_ATTRIBUTES          Groups;
} TOKEN_LOGGING_INFORMATION, *PTOKEN_LOGGING_INFORMATION;