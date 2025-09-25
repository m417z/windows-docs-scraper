ULONG TcRegisterClient(
  [in]  ULONG                 TciVersion,
  [in]  HANDLE                ClRegCtx,
  [in]  PTCI_CLIENT_FUNC_LIST ClientHandlerList,
  [out] PHANDLE               pClientHandle
);