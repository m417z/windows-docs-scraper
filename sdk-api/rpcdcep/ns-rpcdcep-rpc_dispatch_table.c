typedef struct {
  unsigned int          DispatchTableCount;
  RPC_DISPATCH_FUNCTION *DispatchTable;
  LONG_PTR              Reserved;
} RPC_DISPATCH_TABLE, *PRPC_DISPATCH_TABLE;