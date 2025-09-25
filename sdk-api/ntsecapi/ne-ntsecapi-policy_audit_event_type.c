typedef enum _POLICY_AUDIT_EVENT_TYPE {
  AuditCategorySystem = 0,
  AuditCategoryLogon,
  AuditCategoryObjectAccess,
  AuditCategoryPrivilegeUse,
  AuditCategoryDetailedTracking,
  AuditCategoryPolicyChange,
  AuditCategoryAccountManagement,
  AuditCategoryDirectoryServiceAccess,
  AuditCategoryAccountLogon
} POLICY_AUDIT_EVENT_TYPE, *PPOLICY_AUDIT_EVENT_TYPE;