typedef struct {
  unsigned long      Version;
  RPC_IF_HANDLE      IfSpec;
  UUID               *MgrTypeUuid;
  RPC_MGR_EPV        *MgrEpv;
  unsigned int       Flags;
  unsigned int       MaxCalls;
  unsigned int       MaxRpcSize;
  RPC_IF_CALLBACK_FN *IfCallback;
  UUID_VECTOR        *UuidVector;
  RPC_CSTR           Annotation;
  void               *SecurityDescriptor;
} RPC_INTERFACE_TEMPLATEA, *PRPC_INTERFACE_TEMPLATEA;