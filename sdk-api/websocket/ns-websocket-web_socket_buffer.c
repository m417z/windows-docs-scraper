typedef union _WEB_SOCKET_BUFFER {
  struct {
    PBYTE pbBuffer;
    ULONG ulBufferLength;
  } Data;
  struct {
    PBYTE  pbReason;
    ULONG  ulReasonLength;
    USHORT usStatus;
  } CloseStatus;
} WEB_SOCKET_BUFFER, *PWEB_SOCKET_BUFFER;