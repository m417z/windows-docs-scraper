typedef struct _FEATURE_DATA_WRITE_PROTECT {
  FEATURE_HEADER Header;
  UCHAR          SupportsSWPPBit : 1;
  UCHAR          SupportsPersistentWriteProtect : 1;
  UCHAR          WriteInhibitDCB : 1;
  UCHAR          DiscWriteProtectPAC : 1;
  UCHAR          Reserved01 : 4;
  UCHAR          Reserved2[3];
} FEATURE_DATA_WRITE_PROTECT, *PFEATURE_DATA_WRITE_PROTECT;