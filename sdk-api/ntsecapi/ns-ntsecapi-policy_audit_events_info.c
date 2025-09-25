typedef struct _POLICY_AUDIT_EVENTS_INFO {
  BOOLEAN                     AuditingMode;
  PPOLICY_AUDIT_EVENT_OPTIONS EventAuditingOptions;
  ULONG                       MaximumAuditEventCount;
} POLICY_AUDIT_EVENTS_INFO, *PPOLICY_AUDIT_EVENTS_INFO;