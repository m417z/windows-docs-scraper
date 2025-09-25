typedef struct _FEATURE_DATA_DEFECT_MANAGEMENT {
  FEATURE_HEADER Header;
  UCHAR          Reserved1 : 7;
  UCHAR          SupplimentalSpareArea : 1;
  UCHAR          Reserved2[3];
} FEATURE_DATA_DEFECT_MANAGEMENT, *PFEATURE_DATA_DEFECT_MANAGEMENT;