typedef struct _QOS_DIFFSERV {
  QOS_OBJECT_HDR ObjectHdr;
  ULONG          DSFieldCount;
  UCHAR          DiffservRule[1];
} QOS_DIFFSERV, *LPQOS_DIFFSERV;