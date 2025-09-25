typedef struct _PTP_VENDOR_DATA_IN {
  WORD  OpCode;
  DWORD SessionId;
  DWORD TransactionId;
  DWORD Params[PTP_MAX_PARAMS];
  DWORD NumParams;
  DWORD NextPhase;
  BYTE  VendorWriteData[1];
} PTP_VENDOR_DATA_IN, *PPTP_VENDOR_DATA_IN;