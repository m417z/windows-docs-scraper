typedef struct _WTSINFOEX_LEVEL1_A {
  ULONG                  SessionId;
  WTS_CONNECTSTATE_CLASS SessionState;
  LONG                   SessionFlags;
  CHAR                   WinStationName[WINSTATIONNAME_LENGTH + 1];
  CHAR                   UserName[USERNAME_LENGTH + 1];
  CHAR                   DomainName[DOMAIN_LENGTH + 1];
  LARGE_INTEGER          LogonTime;
  LARGE_INTEGER          ConnectTime;
  LARGE_INTEGER          DisconnectTime;
  LARGE_INTEGER          LastInputTime;
  LARGE_INTEGER          CurrentTime;
  DWORD                  IncomingBytes;
  DWORD                  OutgoingBytes;
  DWORD                  IncomingFrames;
  DWORD                  OutgoingFrames;
  DWORD                  IncomingCompressedBytes;
  DWORD                  OutgoingCompressedBytes;
} WTSINFOEX_LEVEL1_A, *PWTSINFOEX_LEVEL1_A;