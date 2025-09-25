typedef struct _PosBarcodeScannerErrorOccurredEventData {
  PosEventDataHeader                     Header;
  LONG                                   IsRetriable;
  DriverUnifiedPosErrorSeverity          Severity;
  UINT32                                 VendorErrorCode;
  DriverUnifiedPosErrorReason            Reason;
  UINT32                                 ExtendedReason;
  UINT32                                 MessageLength;
  PosBarcodeScannerDataReceivedEventData PartialData;
} PosBarcodeScannerErrorOccurredEventData;