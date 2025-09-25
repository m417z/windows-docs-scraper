typedef struct _REG_ENUMERATE_KEY_INFORMATION {
  PVOID                 Object;
  ULONG                 Index;
  KEY_INFORMATION_CLASS KeyInformationClass;
  PVOID                 KeyInformation;
  ULONG                 Length;
  PULONG                ResultLength;
  PVOID                 CallContext;
  PVOID                 ObjectContext;
  PVOID                 Reserved;
} REG_ENUMERATE_KEY_INFORMATION, *PREG_ENUMERATE_KEY_INFORMATION;