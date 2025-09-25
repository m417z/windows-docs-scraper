typedef struct _NET_BUFFER_LIST_CONTEXT {
  NET_BUFFER_LIST_CONTEXT *Next;
  USHORT                  Size;
  USHORT                  Offset;
  UCHAR                   ContextData[];
} NET_BUFFER_LIST_CONTEXT, *PNET_BUFFER_LIST_CONTEXT;