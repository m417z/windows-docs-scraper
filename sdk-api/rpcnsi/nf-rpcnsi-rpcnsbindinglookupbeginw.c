RPC_STATUS RpcNsBindingLookupBeginW(
  unsigned long EntryNameSyntax,
  RPC_WSTR      EntryName,
  RPC_IF_HANDLE IfSpec,
  UUID          *ObjUuid,
  unsigned long BindingMaxCount,
  RPC_NS_HANDLE *LookupContext
);