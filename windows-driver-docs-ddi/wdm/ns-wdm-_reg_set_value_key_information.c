typedef struct _REG_SET_VALUE_KEY_INFORMATION {
  PVOID           Object;
  PUNICODE_STRING ValueName;
  ULONG           TitleIndex;
  ULONG           Type;
  PVOID           Data;
  ULONG           DataSize;
  PVOID           CallContext;
  PVOID           ObjectContext;
  PVOID           Reserved;
} REG_SET_VALUE_KEY_INFORMATION, *PREG_SET_VALUE_KEY_INFORMATION;