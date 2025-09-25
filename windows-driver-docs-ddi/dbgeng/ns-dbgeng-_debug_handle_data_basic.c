typedef struct _DEBUG_HANDLE_DATA_BASIC {
  ULONG TypeNameSize;
  ULONG ObjectNameSize;
  ULONG Attributes;
  ULONG GrantedAccess;
  ULONG HandleCount;
  ULONG PointerCount;
} DEBUG_HANDLE_DATA_BASIC, *PDEBUG_HANDLE_DATA_BASIC;