typedef struct _FEATURE_DATA_FIRMWARE_DATE {
  FEATURE_HEADER Header;
  UCHAR          Year[4];
  UCHAR          Month[2];
  UCHAR          Day[2];
  UCHAR          Hour[2];
  UCHAR          Minute[2];
  UCHAR          Seconds[2];
  UCHAR          Reserved[2];
} FEATURE_DATA_FIRMWARE_DATE, *PFEATURE_DATA_FIRMWARE_DATE;