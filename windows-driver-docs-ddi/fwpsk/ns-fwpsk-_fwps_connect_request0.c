typedef struct _FWPS_CONNECT_REQUEST0 {
  SOCKADDR_STORAGE              localAddressAndPort;
  SOCKADDR_STORAGE              remoteAddressAndPort;
  UINT64                        portReservationToken;
  DWORD                         localRedirectTargetPID;
  struct _FWPS_CONNECT_REQUEST0 *previousVersion;
  UINT64                        modifierFilterId;
  HANDLE                        localRedirectHandle;
  void                          *localRedirectContext;
  SIZE_T                        localRedirectContextSize;
} FWPS_CONNECT_REQUEST0;