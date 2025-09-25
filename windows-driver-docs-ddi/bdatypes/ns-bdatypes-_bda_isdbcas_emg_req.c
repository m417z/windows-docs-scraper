typedef struct _BDA_ISDBCAS_EMG_REQ {
  BYTE bCLA;
  BYTE bINS;
  BYTE bP1;
  BYTE bP2;
  BYTE bLC;
  BYTE bCardId[6];
  BYTE bProtocol;
  BYTE bCABroadcasterGroupId;
  BYTE bMessageControl;
  BYTE bMessageCode[MIN_DIMENSION];
} BDA_ISDBCAS_EMG_REQ, *PBDA_ISDBCAS_EMG_REQ;