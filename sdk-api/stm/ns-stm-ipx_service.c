typedef struct _IPX_SERVICE {
  ULONG            InterfaceIndex;
  ULONG            Protocol;
  IPX_SERVER_ENTRY Server;
} IPX_SERVICE, *PIPX_SERVICE;