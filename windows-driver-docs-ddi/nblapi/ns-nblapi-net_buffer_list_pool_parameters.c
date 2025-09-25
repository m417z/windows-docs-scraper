typedef struct _NET_BUFFER_LIST_POOL_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  UCHAR              ProtocolId;
  BOOLEAN            fAllocateNetBuffer;
  USHORT             ContextSize;
  ULONG              PoolTag;
  ULONG              DataSize;
  ULONG              Flags;
} NET_BUFFER_LIST_POOL_PARAMETERS, *PNET_BUFFER_LIST_POOL_PARAMETERS;