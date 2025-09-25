typedef struct _NET_BUFFER_LIST {
  union {
    struct {
      NET_BUFFER_LIST *Next;
      NET_BUFFER      *FirstNetBuffer;
    };
    SLIST_HEADER           Link;
    NET_BUFFER_LIST_HEADER NetBufferListHeader;
  };
  NET_BUFFER_LIST_CONTEXT *Context;
  NET_BUFFER_LIST         *ParentNetBufferList;
  NDIS_HANDLE             NdisPoolHandle;
  PVOID                   NdisReserved[2];
  PVOID                   ProtocolReserved[4];
  PVOID                   MiniportReserved[2];
  PVOID                   Scratch;
  NDIS_HANDLE             SourceHandle;
  ULONG                   NblFlags;
  LONG                    ChildRefCount;
  ULONG                   Flags;
  union {
    NDIS_STATUS Status;
    ULONG       NdisReserved2;
  };
  PVOID                   NetBufferListInfo[MaxNetBufferListInfo];
} NET_BUFFER_LIST, *PNET_BUFFER_LIST;