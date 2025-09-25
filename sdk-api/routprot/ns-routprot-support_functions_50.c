typedef struct _SUPPORT_FUNCTIONS_50 {
  union {
    ULONGLONG _Align8;
    struct {
      DWORD dwVersion;
      DWORD dwReserved;
    };
  };
  DWORD( )(DWORD ProtocolId,DWORD InterfaceIndex) *DemandDialRequest;
  DWORD( )(DWORD ProtocolId,DWORD InterfaceIndex,DWORD InterfaceReceiveType,BOOL bActivate) *SetInterfaceReceiveType;
  DWORD( )(DWORD ProtocolId,PVOID RouteInfo,PVOID DestAddress) *ValidateRoute;
  DWORD( )(DWORD dwRoutingPid,DWORD dwEntrySize,LPVOID lpEntry) *MIBEntryCreate;
  DWORD( )(DWORD dwRoutingPid,DWORD dwEntrySize,LPVOID lpEntry) *MIBEntryDelete;
  DWORD( )(DWORD dwRoutingPid,DWORD dwEntrySize,LPVOID lpEntry) *MIBEntrySet;
  DWORD( )(DWORD dwRoutingPid,DWORD dwInEntrySize,LPVOID lpInEntry,LPDWORD lpOutEntrySize,LPVOID lpOutEntry) *MIBEntryGet;
  DWORD( )(DWORD dwRoutingPid,DWORD dwInEntrySize,LPVOID lpInEntry,LPDWORD lpOutEntrySize,LPVOID lpOutEntry) *MIBEntryGetFirst;
  DWORD( )(DWORD dwRoutingPid,DWORD dwInEntrySize,LPVOID lpInEntry,LPDWORD lpOutEntrySize,LPVOID lpOutEntry) *MIBEntryGetNext;
  DWORD( )(VOID) *GetRouterId;
  BOOL( )(DWORD dwIfIndex,DWORD dwGroupAddress)  *HasMulticastBoundary;
} SUPPORT_FUNCTIONS_50;