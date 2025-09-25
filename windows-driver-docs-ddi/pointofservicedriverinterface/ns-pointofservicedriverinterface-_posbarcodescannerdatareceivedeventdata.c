typedef struct _PosBarcodeScannerDataReceivedEventData {
  PosEventDataHeader Header;
  UINT32             DataType;
  UINT32             ScanDataLength;
  UINT32             ScanDataLabelLength;
} PosBarcodeScannerDataReceivedEventData;