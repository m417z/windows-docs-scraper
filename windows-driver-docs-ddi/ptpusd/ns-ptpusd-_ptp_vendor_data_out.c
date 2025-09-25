typedef struct _PTP_VENDOR_DATA_OUT {
  WORD  ResponseCode;
  DWORD SessionId;
  DWORD TransactionId;
  DWORD Params[PTP_MAX_PARAMS];
  BYTE  VendorReadData[1];
} PTP_VENDOR_DATA_OUT, *PPTP_VENDOR_DATA_OUT;