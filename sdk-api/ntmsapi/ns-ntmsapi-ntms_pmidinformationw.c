typedef struct _NTMS_PMIDINFORMATIONW {
  NTMS_GUID CurrentLibrary;
  NTMS_GUID MediaPool;
  NTMS_GUID Location;
  DWORD     LocationType;
  NTMS_GUID MediaType;
  NTMS_GUID HomeSlot;
  WCHAR     szBarCode[NTMS_BARCODE_LENGTH];
  DWORD     BarCodeState;
  WCHAR     szSequenceNumber[NTMS_SEQUENCE_LENGTH];
  DWORD     MediaState;
  DWORD     dwNumberOfPartitions;
  DWORD     dwMediaTypeCode;
  DWORD     dwDensityCode;
  NTMS_GUID MountedPartition;
} NTMS_PMIDINFORMATIONW;