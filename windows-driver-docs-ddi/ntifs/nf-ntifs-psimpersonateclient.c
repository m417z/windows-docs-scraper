NTSTATUS PsImpersonateClient(
  [in, out] PETHREAD                     Thread,
  [in]      PACCESS_TOKEN                Token,
  [in]      BOOLEAN                      CopyOnOpen,
  [in]      BOOLEAN                      EffectiveOnly,
  [in]      SECURITY_IMPERSONATION_LEVEL ImpersonationLevel
);