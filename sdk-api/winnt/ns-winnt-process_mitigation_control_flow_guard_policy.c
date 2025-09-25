typedef struct _PROCESS_MITIGATION_CONTROL_FLOW_GUARD_POLICY {
  union {
    DWORD Flags;
    struct {
      DWORD EnableControlFlowGuard : 1;
      DWORD EnableExportSuppression : 1;
      DWORD StrictMode : 1;
      DWORD EnableXfg : 1;
      DWORD EnableXfgAuditMode : 1;
      DWORD ReservedFlags : 27;
    } DUMMYSTRUCTNAME;
  } DUMMYUNIONNAME;
} PROCESS_MITIGATION_CONTROL_FLOW_GUARD_POLICY, *PPROCESS_MITIGATION_CONTROL_FLOW_GUARD_POLICY;