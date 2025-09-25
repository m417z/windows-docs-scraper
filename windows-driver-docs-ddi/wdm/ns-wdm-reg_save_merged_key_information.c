typedef struct _REG_SAVE_MERGED_KEY_INFORMATION {
  PVOID  Object;
  HANDLE FileHandle;
  PVOID  HighKeyObject;
  PVOID  LowKeyObject;
  PVOID  CallContext;
  PVOID  ObjectContext;
  PVOID  Reserved;
} REG_SAVE_MERGED_KEY_INFORMATION, *PREG_SAVE_MERGED_KEY_INFORMATION;