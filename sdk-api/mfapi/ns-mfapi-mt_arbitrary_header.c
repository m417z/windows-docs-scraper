typedef struct _MT_ARBITRARY_HEADER {
  GUID  majortype;
  GUID  subtype;
  BOOL  bFixedSizeSamples;
  BOOL  bTemporalCompression;
  ULONG lSampleSize;
  GUID  formattype;
} MT_ARBITRARY_HEADER;