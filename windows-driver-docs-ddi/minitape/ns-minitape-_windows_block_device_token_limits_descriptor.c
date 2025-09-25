typedef struct _WINDOWS_BLOCK_DEVICE_TOKEN_LIMITS_DESCRIPTOR {
  UCHAR DescriptorType[2];
  UCHAR DescriptorLength[2];
  UCHAR VendorSpecific[6];
  UCHAR MaximumRangeDescriptors[2];
  UCHAR MaximumInactivityTimer[4];
  UCHAR DefaultInactivityTimer[4];
  UCHAR MaximumTokenTransferSize[8];
  UCHAR OptimalTransferCount[8];
} WINDOWS_BLOCK_DEVICE_TOKEN_LIMITS_DESCRIPTOR, *PWINDOWS_BLOCK_DEVICE_TOKEN_LIMITS_DESCRIPTOR;