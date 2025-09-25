typedef struct _REG_SAVE_KEY_INFORMATION {
  PVOID  Object;
  HANDLE FileHandle;
  ULONG  Format;
  PVOID  CallContext;
  PVOID  ObjectContext;
  PVOID  Reserved;
} REG_SAVE_KEY_INFORMATION, *PREG_SAVE_KEY_INFORMATION;