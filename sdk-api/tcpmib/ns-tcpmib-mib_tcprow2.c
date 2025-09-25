typedef struct _MIB_TCPROW2 {
  DWORD                        dwState;
  DWORD                        dwLocalAddr;
  DWORD                        dwLocalPort;
  DWORD                        dwRemoteAddr;
  DWORD                        dwRemotePort;
  DWORD                        dwOwningPid;
  TCP_CONNECTION_OFFLOAD_STATE dwOffloadState;
} MIB_TCPROW2, *PMIB_TCPROW2;