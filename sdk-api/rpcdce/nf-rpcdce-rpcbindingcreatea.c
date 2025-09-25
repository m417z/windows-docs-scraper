RPC_STATUS RpcBindingCreateA(
  [in]           RPC_BINDING_HANDLE_TEMPLATE_V1_A *Template,
  [in, optional] RPC_BINDING_HANDLE_SECURITY_V1_A *Security,
  [in, optional] RPC_BINDING_HANDLE_OPTIONS_V1    *Options,
  [out]          RPC_BINDING_HANDLE               *Binding
);