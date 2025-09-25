typedef struct _RPC_BINDING_VECTOR {
  unsigned long      Count;
  RPC_BINDING_HANDLE BindingH[1];
} RPC_BINDING_VECTOR;