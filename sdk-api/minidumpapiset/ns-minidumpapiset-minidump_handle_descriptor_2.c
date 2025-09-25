typedef struct _MINIDUMP_HANDLE_DESCRIPTOR_2 {
  ULONG64 Handle;
  RVA     TypeNameRva;
  RVA     ObjectNameRva;
  ULONG32 Attributes;
  ULONG32 GrantedAccess;
  ULONG32 HandleCount;
  ULONG32 PointerCount;
  RVA     ObjectInfoRva;
  ULONG32 Reserved0;
} MINIDUMP_HANDLE_DESCRIPTOR_2, *PMINIDUMP_HANDLE_DESCRIPTOR_2;