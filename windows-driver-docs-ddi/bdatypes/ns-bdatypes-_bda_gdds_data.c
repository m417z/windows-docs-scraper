typedef struct _BDA_GDDS_DATA {
  PBDARESULT lResult;
  ULONG      ulDataLength;
  ULONG      ulPercentageProgress;
  BYTE       argbData[MIN_DIMENSION];
} BDA_GDDS_DATA, *P_BDA_GDDS_DATA;