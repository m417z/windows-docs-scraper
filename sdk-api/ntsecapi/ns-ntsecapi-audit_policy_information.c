typedef struct _AUDIT_POLICY_INFORMATION {
  GUID  AuditSubCategoryGuid;
  ULONG AuditingInformation;
  GUID  AuditCategoryGuid;
} AUDIT_POLICY_INFORMATION, *PAUDIT_POLICY_INFORMATION;