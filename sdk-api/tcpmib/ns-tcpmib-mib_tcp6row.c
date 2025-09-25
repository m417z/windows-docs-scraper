typedef struct _MIB_TCP6ROW {
  MIB_TCP_STATE State;
  IN6_ADDR      LocalAddr;
  DWORD         dwLocalScopeId;
  DWORD         dwLocalPort;
  IN6_ADDR      RemoteAddr;
  DWORD         dwRemoteScopeId;
  DWORD         dwRemotePort;
} MIB_TCP6ROW, *PMIB_TCP6ROW;