typedef struct _ACCESS_STATE {
  LUID                     OperationID;
  BOOLEAN                  SecurityEvaluated;
  BOOLEAN                  GenerateAudit;
  BOOLEAN                  GenerateOnClose;
  BOOLEAN                  PrivilegesAllocated;
  ULONG                    Flags;
  ACCESS_MASK              RemainingDesiredAccess;
  ACCESS_MASK              PreviouslyGrantedAccess;
  ACCESS_MASK              OriginalDesiredAccess;
  SECURITY_SUBJECT_CONTEXT SubjectSecurityContext;
  PSECURITY_DESCRIPTOR     SecurityDescriptor;
  PVOID                    AuxData;
  union {
    INITIAL_PRIVILEGE_SET InitialPrivilegeSet;
    PRIVILEGE_SET         PrivilegeSet;
  } Privileges;
  BOOLEAN                  AuditPrivileges;
  UNICODE_STRING           ObjectName;
  UNICODE_STRING           ObjectTypeName;
} ACCESS_STATE, *PACCESS_STATE;