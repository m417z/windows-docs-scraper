typedef struct _NET_INTERFACE_CONTEXT_TABLE {
  HANDLE                InterfaceContextHandle;
  UINT                  NumberOfEntries;
  NET_INTERFACE_CONTEXT *InterfaceContextArray;
} NET_INTERFACE_CONTEXT_TABLE;