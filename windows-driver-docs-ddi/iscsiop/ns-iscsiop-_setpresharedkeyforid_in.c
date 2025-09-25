typedef struct _SetPresharedKeyForId_IN {
  ULONG     PortNumber;
  ULONGLONG SecurityFlags;
  UCHAR     IdType;
  ULONG     IdSize;
  ULONG     KeySize;
  UCHAR     Id[1];
} SetPresharedKeyForId_IN, *PSetPresharedKeyForId_IN;