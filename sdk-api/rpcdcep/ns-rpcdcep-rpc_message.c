typedef struct _RPC_MESSAGE {
  RPC_BINDING_HANDLE     Handle;
  unsigned long          DataRepresentation;
  void                   *Buffer;
  unsigned int           BufferLength;
  unsigned int           ProcNum;
  PRPC_SYNTAX_IDENTIFIER TransferSyntax;
  void                   *RpcInterfaceInformation;
  void                   *ReservedForRuntime;
  RPC_MGR_EPV            *ManagerEpv;
  void                   *ImportContext;
  unsigned long          RpcFlags;
} RPC_MESSAGE, *PRPC_MESSAGE;