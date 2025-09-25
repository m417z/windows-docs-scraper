typedef struct _WSAOVERLAPPED {
  DWORD    Internal;
  DWORD    InternalHigh;
  DWORD    Offset;
  DWORD    OffsetHigh;
  WSAEVENT hEvent;
} WSAOVERLAPPED, *LPWSAOVERLAPPED;