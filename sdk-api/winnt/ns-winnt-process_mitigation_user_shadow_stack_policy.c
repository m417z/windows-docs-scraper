typedef struct _PROCESS_MITIGATION_USER_SHADOW_STACK_POLICY {
  union {
    DWORD Flags;
    struct {
      DWORD EnableUserShadowStack : 1;
      DWORD AuditUserShadowStack : 1;
      DWORD SetContextIpValidation : 1;
      DWORD AuditSetContextIpValidation : 1;
      DWORD EnableUserShadowStackStrictMode : 1;
      DWORD BlockNonCetBinaries : 1;
      DWORD BlockNonCetBinariesNonEhcont : 1;
      DWORD AuditBlockNonCetBinaries : 1;
      DWORD CetDynamicApisOutOfProcOnly : 1;
      DWORD SetContextIpValidationRelaxedMode : 1;
      DWORD ReservedFlags : 22;
    } DUMMYSTRUCTNAME;
  } DUMMYUNIONNAME;
} PROCESS_MITIGATION_USER_SHADOW_STACK_POLICY, *PPROCESS_MITIGATION_USER_SHADOW_STACK_POLICY;