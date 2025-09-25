typedef struct _NTMS_PMIDINFORMATIONA {
  NTMS_GUID CurrentLibrary;
  NTMS_GUID MediaPool;
  NTMS_GUID Location;
  DWORD     LocationType;
  NTMS_GUID MediaType;
  NTMS_GUID HomeSlot;
  CHAR      szBarCode[NTMS_BARCODE_LENGTH];
  DWORD     BarCodeState;
  CHAR      szSequenceNumber[NTMS_SEQUENCE_LENGTH];
  DWORD     MediaState;
  DWORD     dwNumberOfPartitions;
  DWORD     dwMediaTypeCode;
  DWORD     dwDensityCode;
  NTMS_GUID MountedPartition;
} NTMS_PMIDINFORMATIONA;