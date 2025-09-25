typedef struct _REG_RESTORE_KEY_INFORMATION {
  PVOID  Object;
  HANDLE FileHandle;
  ULONG  Flags;
  PVOID  CallContext;
  PVOID  ObjectContext;
  PVOID  Reserved;
} REG_RESTORE_KEY_INFORMATION, *PREG_RESTORE_KEY_INFORMATION;