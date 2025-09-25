typedef struct _LSA_LAST_INTER_LOGON_INFO {
  LARGE_INTEGER LastSuccessfulLogon;
  LARGE_INTEGER LastFailedLogon;
  ULONG         FailedAttemptCountSinceLastSuccessfulLogon;
} LSA_LAST_INTER_LOGON_INFO, *PLSA_LAST_INTER_LOGON_INFO;