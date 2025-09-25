typedef struct _GetPresharedKeyForId_IN {
  ULONG PortNumber;
  UCHAR IdType;
  ULONG IdSize;
  UCHAR Id[1];
} GetPresharedKeyForId_IN, *PGetPresharedKeyForId_IN;