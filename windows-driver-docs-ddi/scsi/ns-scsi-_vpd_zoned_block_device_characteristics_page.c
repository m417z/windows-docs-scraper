typedef struct _VPD_ZONED_BLOCK_DEVICE_CHARACTERISTICS_PAGE {
  UCHAR DeviceType : 5;
  UCHAR DeviceTypeQualifier : 3;
  UCHAR PageCode;
  UCHAR PageLength[2];
  UCHAR URSWRZ : 1;
  UCHAR Reserved1 : 7;
  UCHAR Reserved2[3];
  UCHAR OptimalNumberOfOpenSequentialWritePreferredZone[4];
  UCHAR OptimalNumberOfNonSequentiallyWrittenSequentialWritePreferredZone[4];
  UCHAR MaxNumberOfOpenSequentialWriteRequiredZone[4];
  UCHAR Reserved3[44];
} VPD_ZONED_BLOCK_DEVICE_CHARACTERISTICS_PAGE, *PVPD_ZONED_BLOCK_DEVICE_CHARACTERISTICS_PAGE;