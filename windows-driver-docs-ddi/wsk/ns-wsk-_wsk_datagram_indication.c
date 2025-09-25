typedef struct _WSK_DATAGRAM_INDICATION {
  struct _WSK_DATAGRAM_INDICATION *Next;
  WSK_BUF                         Buffer;
  PCMSGHDR                        ControlInfo;
  ULONG                           ControlInfoLength;
  PSOCKADDR                       RemoteAddress;
} WSK_DATAGRAM_INDICATION, *PWSK_DATAGRAM_INDICATION;