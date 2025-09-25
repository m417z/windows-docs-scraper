typedef struct tagWNODE_SINGLE_ITEM {
  struct _WNODE_HEADER WnodeHeader;
  ULONG                OffsetInstanceName;
  ULONG                InstanceIndex;
  ULONG                ItemId;
  ULONG                DataBlockOffset;
  ULONG                SizeDataItem;
  UCHAR                VariableData[];
} WNODE_SINGLE_ITEM, *PWNODE_SINGLE_ITEM;