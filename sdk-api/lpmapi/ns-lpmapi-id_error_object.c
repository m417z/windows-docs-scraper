typedef struct {
  USHORT usIdErrLength;
  UCHAR  ucAType;
  UCHAR  ucSubType;
  USHORT usReserved;
  USHORT usIdErrorValue;
  UCHAR  ucIdErrData[4];
} ID_ERROR_OBJECT;