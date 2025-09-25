typedef struct _MINIDUMP_HANDLE_DESCRIPTOR {
  ULONG64 Handle;
  RVA     TypeNameRva;
  RVA     ObjectNameRva;
  ULONG32 Attributes;
  ULONG32 GrantedAccess;
  ULONG32 HandleCount;
  ULONG32 PointerCount;
} MINIDUMP_HANDLE_DESCRIPTOR, *PMINIDUMP_HANDLE_DESCRIPTOR;