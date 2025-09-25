typedef struct _PROCESS_MITIGATION_CHILD_PROCESS_POLICY {
  union {
    ULONG Flags;
    struct {
      ULONG NoChildProcessCreation : 1;
      ULONG AuditNoChildProcessCreation : 1;
      ULONG AllowSecureProcessCreation : 1;
      ULONG ReservedFlags : 29;
    } DUMMYSTRUCTNAME;
  } DUMMYUNIONNAME;
} PROCESS_MITIGATION_CHILD_PROCESS_POLICY, *PPROCESS_MITIGATION_CHILD_PROCESS_POLICY;