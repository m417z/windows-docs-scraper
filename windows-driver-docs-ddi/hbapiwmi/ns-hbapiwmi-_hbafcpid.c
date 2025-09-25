typedef struct _HBAFCPID {
  ULONG     Fcid;
  UCHAR     NodeWWN[8];
  UCHAR     PortWWN[8];
  ULONGLONG FcpLun;
} HBAFCPID, *PHBAFCPID;