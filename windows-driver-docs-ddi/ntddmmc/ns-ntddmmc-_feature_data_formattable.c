typedef struct _FEATURE_DATA_FORMATTABLE {
  FEATURE_HEADER Header;
  UCHAR          FullCertification : 1;
  UCHAR          QuickCertification : 1;
  UCHAR          SpareAreaExpansion : 1;
  UCHAR          RENoSpareAllocated : 1;
  UCHAR          Reserved1 : 4;
  UCHAR          Reserved2[3];
  UCHAR          RRandomWritable : 1;
  UCHAR          Reserved3 : 7;
  UCHAR          Reserved4[3];
} FEATURE_DATA_FORMATTABLE, *PFEATURE_DATA_FORMATTABLE;