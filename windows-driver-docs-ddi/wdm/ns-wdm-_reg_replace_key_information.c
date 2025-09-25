typedef struct _REG_REPLACE_KEY_INFORMATION {
  PVOID           Object;
  PUNICODE_STRING OldFileName;
  PUNICODE_STRING NewFileName;
  PVOID           CallContext;
  PVOID           ObjectContext;
  PVOID           Reserved;
} REG_REPLACE_KEY_INFORMATION, *PREG_REPLACE_KEY_INFORMATION;