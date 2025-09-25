typedef struct _REG_QUERY_KEY_INFORMATION {
  PVOID                 Object;
  KEY_INFORMATION_CLASS KeyInformationClass;
  PVOID                 KeyInformation;
  ULONG                 Length;
  PULONG                ResultLength;
  PVOID                 CallContext;
  PVOID                 ObjectContext;
  PVOID                 Reserved;
} REG_QUERY_KEY_INFORMATION, *PREG_QUERY_KEY_INFORMATION;