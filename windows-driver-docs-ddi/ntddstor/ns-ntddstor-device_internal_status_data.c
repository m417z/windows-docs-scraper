typedef struct _DEVICE_INTERNAL_STATUS_DATA {
  ULONG     Version;
  ULONG     Size;
  ULONGLONG T10VendorId;
  ULONG     DataSet1Length;
  ULONG     DataSet2Length;
  ULONG     DataSet3Length;
  ULONG     DataSet4Length;
  UCHAR     StatusDataVersion;
  UCHAR     Reserved[3];
  UCHAR     ReasonIdentifier[128];
  ULONG     StatusDataLength;
  UCHAR     StatusData[ANYSIZE_ARRAY];
} DEVICE_INTERNAL_STATUS_DATA, *PDEVICE_INTERNAL_STATUS_DATA;