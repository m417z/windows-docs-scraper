typedef struct _BDA_DISEQC_SEND {
  ULONG ulRequestId;
  ULONG ulPacketLength;
  BYTE  argbPacketData[8];
} BDA_DISEQC_SEND, *PBDA_DISEQC_SEND;