typedef struct tagWNODE_EVENT_REFERENCE {
  struct _WNODE_HEADER WnodeHeader;
  GUID                 TargetGuid;
  ULONG                TargetDataBlockSize;
  union {
    ULONG TargetInstanceIndex;
    WCHAR TargetInstanceName[];
  } DUMMYUNIONNAME;
} WNODE_EVENT_REFERENCE, *PWNODE_EVENT_REFERENCE;