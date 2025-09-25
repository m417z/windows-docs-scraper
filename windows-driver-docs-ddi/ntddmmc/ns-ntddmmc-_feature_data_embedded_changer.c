typedef struct _FEATURE_DATA_EMBEDDED_CHANGER {
  FEATURE_HEADER Header;
  UCHAR          Reserved1 : 2;
  UCHAR          SupportsDiscPresent : 1;
  UCHAR          Reserved2 : 1;
  UCHAR          SideChangeCapable : 1;
  UCHAR          Reserved3 : 3;
  UCHAR          Reserved4[2];
  UCHAR          HighestSlotNumber : 5;
  UCHAR          Reserved : 3;
} FEATURE_DATA_EMBEDDED_CHANGER, *PFEATURE_DATA_EMBEDDED_CHANGER;