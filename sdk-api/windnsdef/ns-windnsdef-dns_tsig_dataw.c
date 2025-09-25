typedef struct {
  PWSTR    pNameAlgorithm;
  PBYTE    pAlgorithmPacket;
  PBYTE    pSignature;
  PBYTE    pOtherData;
  LONGLONG i64CreateTime;
  WORD     wFudgeTime;
  WORD     wOriginalXid;
  WORD     wError;
  WORD     wSigLength;
  WORD     wOtherLength;
  UCHAR    cAlgNameLength;
  BOOL     bPacketPointers;
} DNS_TSIG_DATAW, *PDNS_TSIG_DATAW;