typedef struct _BDA_TS_SELECTORINFO {
  BYTE   bTSInfolength;
  BYTE   bReserved[2];
  GUID   guidNetworkType;
  BYTE   bTSIDCount;
  USHORT usTSID[MIN_DIMENSION];
} BDA_TS_SELECTORINFO, *PBDA_TS_SELECTORINFO;