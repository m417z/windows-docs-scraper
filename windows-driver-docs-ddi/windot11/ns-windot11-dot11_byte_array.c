typedef struct DOT11_BYTE_ARRAY {
  NDIS_OBJECT_HEADER Header;
  ULONG              uNumOfBytes;
  ULONG              uTotalNumOfBytes;
  UCHAR              ucBuffer[1];
} DOT11_BYTE_ARRAY, *PDOT11_BYTE_ARRAY;