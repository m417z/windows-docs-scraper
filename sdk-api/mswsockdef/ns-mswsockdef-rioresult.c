typedef struct _RIORESULT {
  LONG      Status;
  ULONG     BytesTransferred;
  ULONGLONG SocketContext;
  ULONGLONG RequestContext;
} RIORESULT, *PRIORESULT;