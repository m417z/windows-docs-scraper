typedef struct _REG_LOAD_KEY_INFORMATION_V2 {
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
  ULONG_PTR       Version;
  PVOID           FileAccessToken;
} REG_LOAD_KEY_INFORMATION_V2, *PREG_LOAD_KEY_INFORMATION_V2;