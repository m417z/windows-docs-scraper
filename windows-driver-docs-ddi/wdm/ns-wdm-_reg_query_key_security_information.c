typedef struct _REG_QUERY_KEY_SECURITY_INFORMATION {
  PVOID                 Object;
  PSECURITY_INFORMATION SecurityInformation;
  PSECURITY_DESCRIPTOR  SecurityDescriptor;
  PULONG                Length;
  PVOID                 CallContext;
  PVOID                 ObjectContext;
  PVOID                 Reserved;
} REG_QUERY_KEY_SECURITY_INFORMATION, *PREG_QUERY_KEY_SECURITY_INFORMATION;