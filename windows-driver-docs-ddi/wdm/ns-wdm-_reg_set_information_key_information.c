typedef struct _REG_SET_INFORMATION_KEY_INFORMATION {
  PVOID                     Object;
  KEY_SET_INFORMATION_CLASS KeySetInformationClass;
  PVOID                     KeySetInformation;
  ULONG                     KeySetInformationLength;
  PVOID                     CallContext;
  PVOID                     ObjectContext;
  PVOID                     Reserved;
} REG_SET_INFORMATION_KEY_INFORMATION, *PREG_SET_INFORMATION_KEY_INFORMATION;