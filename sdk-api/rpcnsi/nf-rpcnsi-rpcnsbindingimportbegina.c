RPC_STATUS RpcNsBindingImportBeginA(
  unsigned long EntryNameSyntax,
  RPC_CSTR      EntryName,
  RPC_IF_HANDLE IfSpec,
  UUID          *ObjUuid,
  RPC_NS_HANDLE *ImportContext
);