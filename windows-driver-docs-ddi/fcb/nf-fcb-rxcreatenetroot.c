PNET_ROOT RxCreateNetRoot(
  [in]           IN PSRV_CALL         SrvCall,
  [in]           IN PUNICODE_STRING   Name,
  [in]           IN ULONG             NetRootFlags,
  [in, optional] IN PRX_CONNECTION_ID RxConnectionId
);