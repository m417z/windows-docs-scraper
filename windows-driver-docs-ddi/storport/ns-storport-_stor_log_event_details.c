typedef struct _STOR_LOG_EVENT_DETAILS {
  ULONG                       InterfaceRevision;
  ULONG                       Size;
  ULONG                       Flags;
  STOR_EVENT_ASSOCIATION_ENUM EventAssociation;
  ULONG                       PathId;
  ULONG                       TargetId;
  ULONG                       LunId;
  BOOLEAN                     StorportSpecificErrorCode;
  ULONG                       ErrorCode;
  ULONG                       UniqueId;
  ULONG                       DumpDataSize;
  PVOID                       DumpData;
  ULONG                       StringCount;
  PWSTR                       *StringList;
} STOR_LOG_EVENT_DETAILS, *PSTOR_LOG_EVENT_DETAILS;