typedef struct _IPX_SERVER_ENTRY {
  USHORT Type;
  UCHAR  Name[48];
  UCHAR  Network[4];
  UCHAR  Node[6];
  UCHAR  Socket[2];
  USHORT HopCount;
} IPX_SERVER_ENTRY, *PIPX_SERVER_ENTRY;