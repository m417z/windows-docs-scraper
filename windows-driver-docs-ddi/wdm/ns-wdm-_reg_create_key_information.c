typedef struct _REG_CREATE_KEY_INFORMATION {
  PUNICODE_STRING CompleteName;
  PVOID           RootObject;
  PVOID           ObjectType;
  ULONG           CreateOptions;
  PUNICODE_STRING Class;
  PVOID           SecurityDescriptor;
  PVOID           SecurityQualityOfService;
  ACCESS_MASK     DesiredAccess;
  ACCESS_MASK     GrantedAccess;
  PULONG          Disposition;
  PVOID           *ResultObject;
  PVOID           CallContext;
  PVOID           RootObjectContext;
  PVOID           Transaction;
  PVOID           Reserved;
} REG_CREATE_KEY_INFORMATION, REG_OPEN_KEY_INFORMATION, *PREG_CREATE_KEY_INFORMATION, *PREG_OPEN_KEY_INFORMATION;