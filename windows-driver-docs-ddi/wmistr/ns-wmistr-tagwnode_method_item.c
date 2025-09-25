typedef struct tagWNODE_METHOD_ITEM {
  struct _WNODE_HEADER WnodeHeader;
  ULONG                OffsetInstanceName;
  ULONG                InstanceIndex;
  ULONG                MethodId;
  ULONG                DataBlockOffset;
  ULONG                SizeDataBlock;
  UCHAR                VariableData[];
} WNODE_METHOD_ITEM, *PWNODE_METHOD_ITEM;