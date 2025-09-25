typedef struct _SECURITY_SUBJECT_CONTEXT {
  PACCESS_TOKEN                ClientToken;
  SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
  PACCESS_TOKEN                PrimaryToken;
  PVOID                        ProcessAuditId;
} SECURITY_SUBJECT_CONTEXT, *PSECURITY_SUBJECT_CONTEXT;