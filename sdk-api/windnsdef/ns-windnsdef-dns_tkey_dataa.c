typedef struct {
  PSTR  pNameAlgorithm;
  PBYTE pAlgorithmPacket;
  PBYTE pKey;
  PBYTE pOtherData;
  DWORD dwCreateTime;
  DWORD dwExpireTime;
  WORD  wMode;
  WORD  wError;
  WORD  wKeyLength;
  WORD  wOtherLength;
  UCHAR cAlgNameLength;
  BOOL  bPacketPointers;
} DNS_TKEY_DATAA, *PDNS_TKEY_DATAA;