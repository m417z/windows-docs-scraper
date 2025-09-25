PACCESS_TOKEN PsReferenceImpersonationToken(
  [in, out] PETHREAD                      Thread,
  [out]     PBOOLEAN                      CopyOnOpen,
  [out]     PBOOLEAN                      EffectiveOnly,
  [out]     PSECURITY_IMPERSONATION_LEVEL ImpersonationLevel
);