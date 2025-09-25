RPC_STATUS RpcNsBindingLookupBeginA(
  unsigned long EntryNameSyntax,
  RPC_CSTR      EntryName,
  RPC_IF_HANDLE IfSpec,
  UUID          *ObjUuid,
  unsigned long BindingMaxCount,
  RPC_NS_HANDLE *LookupContext
);