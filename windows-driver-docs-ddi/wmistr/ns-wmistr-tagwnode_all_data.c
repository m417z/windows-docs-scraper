typedef struct tagWNODE_ALL_DATA {
  struct _WNODE_HEADER WnodeHeader;
  ULONG                DataBlockOffset;
  ULONG                InstanceCount;
  ULONG                OffsetInstanceNameOffsets;
  union {
    ULONG                       FixedInstanceSize;
    OFFSETINSTANCEDATAANDLENGTH OffsetInstanceDataAndLength[];
  } DUMMYUNIONNAME;
} WNODE_ALL_DATA, *PWNODE_ALL_DATA;