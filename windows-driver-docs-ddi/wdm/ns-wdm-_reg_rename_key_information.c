typedef struct _REG_RENAME_KEY_INFORMATION {
  PVOID           Object;
  PUNICODE_STRING NewName;
  PVOID           CallContext;
  PVOID           ObjectContext;
  PVOID           Reserved;
} REG_RENAME_KEY_INFORMATION, *PREG_RENAME_KEY_INFORMATION;