typedef struct _REG_LOAD_KEY_INFORMATION {
  PVOID           Object;
  PUNICODE_STRING KeyName;
  PUNICODE_STRING SourceFile;
  ULONG           Flags;
  PVOID           TrustClassObject;
  PVOID           UserEvent;
  ACCESS_MASK     DesiredAccess;
  PHANDLE         RootHandle;
  PVOID           CallContext;
  PVOID           ObjectContext;
  PVOID           Reserved;
} REG_LOAD_KEY_INFORMATION, *PREG_LOAD_KEY_INFORMATION;