typedef struct _REG_SET_KEY_SECURITY_INFORMATION {
  PVOID                 Object;
  PSECURITY_INFORMATION SecurityInformation;
  PSECURITY_DESCRIPTOR  SecurityDescriptor;
  PVOID                 CallContext;
  PVOID                 ObjectContext;
  PVOID                 Reserved;
} REG_SET_KEY_SECURITY_INFORMATION, *PREG_SET_KEY_SECURITY_INFORMATION;