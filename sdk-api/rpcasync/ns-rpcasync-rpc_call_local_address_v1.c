typedef struct _RPC_CALL_LOCAL_ADDRESS_V1 {
  unsigned int          Version;
  void                  *Buffer;
  unsigned long         BufferSize;
  RpcLocalAddressFormat AddressFormat;
} RPC_CALL_LOCAL_ADDRESS_V1, *PRPC_CALL_LOCAL_ADDRESS_V1;