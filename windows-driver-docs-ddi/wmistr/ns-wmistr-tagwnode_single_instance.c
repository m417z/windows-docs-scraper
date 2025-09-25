typedef struct tagWNODE_SINGLE_INSTANCE {
  struct _WNODE_HEADER WnodeHeader;
  ULONG                OffsetInstanceName;
  ULONG                InstanceIndex;
  ULONG                DataBlockOffset;
  ULONG                SizeDataBlock;
  UCHAR                VariableData[];
} WNODE_SINGLE_INSTANCE, *PWNODE_SINGLE_INSTANCE;