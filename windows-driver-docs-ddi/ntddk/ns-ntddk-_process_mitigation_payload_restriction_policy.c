typedef struct _PROCESS_MITIGATION_PAYLOAD_RESTRICTION_POLICY {
  union {
    ULONG Flags;
    struct {
      ULONG EnableExportAddressFilter : 1;
      ULONG AuditExportAddressFilter : 1;
      ULONG EnableExportAddressFilterPlus : 1;
      ULONG AuditExportAddressFilterPlus : 1;
      ULONG EnableImportAddressFilter : 1;
      ULONG AuditImportAddressFilter : 1;
      ULONG EnableRopStackPivot : 1;
      ULONG AuditRopStackPivot : 1;
      ULONG EnableRopCallerCheck : 1;
      ULONG AuditRopCallerCheck : 1;
      ULONG EnableRopSimExec : 1;
      ULONG AuditRopSimExec : 1;
      ULONG ReservedFlags : 20;
    } DUMMYSTRUCTNAME;
  } DUMMYUNIONNAME;
} PROCESS_MITIGATION_PAYLOAD_RESTRICTION_POLICY, *PPROCESS_MITIGATION_PAYLOAD_RESTRICTION_POLICY;