typedef struct {
  ULONG                 Size;
  ULONG                 Version;
  ULONG                 Age;
  GNSS_FIXDATA_BASIC    BasicData;
  GNSS_FIXDATA_ACCURACY AccuracyData;
} GNSS_AGNSS_INJECTPOSITION, *PGNSS_AGNSS_INJECTPOSITION;