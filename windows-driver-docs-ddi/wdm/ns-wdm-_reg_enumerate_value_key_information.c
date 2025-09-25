typedef struct _REG_ENUMERATE_VALUE_KEY_INFORMATION {
  PVOID                       Object;
  ULONG                       Index;
  KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass;
  PVOID                       KeyValueInformation;
  ULONG                       Length;
  PULONG                      ResultLength;
  PVOID                       CallContext;
  PVOID                       ObjectContext;
  PVOID                       Reserved;
} REG_ENUMERATE_VALUE_KEY_INFORMATION, *PREG_ENUMERATE_VALUE_KEY_INFORMATION;