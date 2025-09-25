typedef struct _MIB_TCP6ROW2 {
  IN6_ADDR                     LocalAddr;
  DWORD                        dwLocalScopeId;
  DWORD                        dwLocalPort;
  IN6_ADDR                     RemoteAddr;
  DWORD                        dwRemoteScopeId;
  DWORD                        dwRemotePort;
  MIB_TCP_STATE                State;
  DWORD                        dwOwningPid;
  TCP_CONNECTION_OFFLOAD_STATE dwOffloadState;
} MIB_TCP6ROW2, *PMIB_TCP6ROW2;