typedef struct _WTSINFOA {
  WTS_CONNECTSTATE_CLASS State;
  DWORD                  SessionId;
  DWORD                  IncomingBytes;
  DWORD                  OutgoingBytes;
  DWORD                  IncomingFrames;
  DWORD                  OutgoingFrames;
  DWORD                  IncomingCompressedBytes;
  DWORD                  OutgoingCompressedBy;
  CHAR                   WinStationName[WINSTATIONNAME_LENGTH];
  CHAR                   Domain[DOMAIN_LENGTH];
  CHAR                   UserName[USERNAME_LENGTH + 1];
  LARGE_INTEGER          ConnectTime;
  LARGE_INTEGER          DisconnectTime;
  LARGE_INTEGER          LastInputTime;
  LARGE_INTEGER          LogonTime;
  LARGE_INTEGER          CurrentTime;
} WTSINFOA, *PWTSINFOA;