typedef struct {
  PWSTR pNameAlgorithm;
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
} DNS_TKEY_DATAW, *PDNS_TKEY_DATAW;