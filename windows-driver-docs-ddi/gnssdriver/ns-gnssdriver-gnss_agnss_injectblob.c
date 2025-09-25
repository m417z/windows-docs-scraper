typedef struct {
  ULONG Size;
  ULONG Version;
  ULONG BlobOui;
  ULONG BlobVersion;
  ULONG AgnssFormat;
  ULONG BlobSize;
  BYTE  BlobData[ANYSIZE_ARRAY];
} GNSS_AGNSS_INJECTBLOB, *PGNSS_AGNSS_INJECTBLOB;