typedef struct _SECURITY_QUALITY_OF_SERVICE {
  DWORD                          Length;
  SECURITY_IMPERSONATION_LEVEL   ImpersonationLevel;
  SECURITY_CONTEXT_TRACKING_MODE ContextTrackingMode;
  BOOLEAN                        EffectiveOnly;
} SECURITY_QUALITY_OF_SERVICE, *PSECURITY_QUALITY_OF_SERVICE;