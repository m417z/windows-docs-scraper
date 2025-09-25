typedef struct _AMMediaType {
  GUID     majortype;
  GUID     subtype;
  BOOL     bFixedSizeSamples;
  BOOL     bTemporalCompression;
  ULONG    lSampleSize;
  GUID     formattype;
  IUnknown *pUnk;
  ULONG    cbFormat;
  BYTE     *pbFormat;
} AM_MEDIA_TYPE;