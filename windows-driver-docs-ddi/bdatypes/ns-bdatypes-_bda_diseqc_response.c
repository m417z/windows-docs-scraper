typedef struct _BDA_DISEQC_RESPONSE {
  ULONG ulRequestId;
  ULONG ulPacketLength;
  BYTE  argbPacketData[8];
} BDA_DISEQC_RESPONSE, *PBDA_DISEQC_RESPONSE;