typedef struct _REG_DELETE_VALUE_KEY_INFORMATION {
  PVOID           Object;
  PUNICODE_STRING ValueName;
  PVOID           CallContext;
  PVOID           ObjectContext;
  PVOID           Reserved;
} REG_DELETE_VALUE_KEY_INFORMATION, *PREG_DELETE_VALUE_KEY_INFORMATION;