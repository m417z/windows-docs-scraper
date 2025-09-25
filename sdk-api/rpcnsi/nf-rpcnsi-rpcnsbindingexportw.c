RPC_STATUS RpcNsBindingExportW(
  unsigned long      EntryNameSyntax,
  RPC_WSTR           EntryName,
  RPC_IF_HANDLE      IfSpec,
  RPC_BINDING_VECTOR *BindingVec,
  UUID_VECTOR        *ObjectUuidVec
);