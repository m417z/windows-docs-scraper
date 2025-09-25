typedef struct _WIA_DATA_TRANSFER_INFO {
  ULONG ulSize;
  ULONG ulSection;
  ULONG ulBufferSize;
  BOOL  bDoubleBuffer;
  ULONG ulReserved1;
  ULONG ulReserved2;
  ULONG ulReserved3;
} WIA_DATA_TRANSFER_INFO, *PWIA_DATA_TRANSFER_INFO;