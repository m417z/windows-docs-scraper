typedef struct _PROCESS_MITIGATION_SYSTEM_CALL_DISABLE_POLICY {
  union {
    DWORD Flags;
    struct {
      DWORD DisallowWin32kSystemCalls : 1;
      DWORD AuditDisallowWin32kSystemCalls : 1;
      DWORD DisallowFsctlSystemCalls : 1;
      DWORD AuditDisallowFsctlSystemCalls : 1;
      DWORD ReservedFlags : 28;
    } DUMMYSTRUCTNAME;
  } DUMMYUNIONNAME;
} PROCESS_MITIGATION_SYSTEM_CALL_DISABLE_POLICY, *PPROCESS_MITIGATION_SYSTEM_CALL_DISABLE_POLICY;