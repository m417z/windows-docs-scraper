typedef struct _FEATURE_DATA_CORE {
  FEATURE_HEADER Header;
  UCHAR          PhysicalInterface[4];
  UCHAR          DeviceBusyEvent : 1;
  UCHAR          INQUIRY2 : 1;
  UCHAR          Reserved1 : 6;
  UCHAR          Reserved2[3];
} FEATURE_DATA_CORE, *PFEATURE_DATA_CORE;