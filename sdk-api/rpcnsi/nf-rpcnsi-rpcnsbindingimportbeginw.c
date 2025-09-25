RPC_STATUS RpcNsBindingImportBeginW(
  unsigned long EntryNameSyntax,
  RPC_WSTR      EntryName,
  RPC_IF_HANDLE IfSpec,
  UUID          *ObjUuid,
  RPC_NS_HANDLE *ImportContext
);