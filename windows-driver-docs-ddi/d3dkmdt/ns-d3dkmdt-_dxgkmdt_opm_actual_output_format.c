typedef struct _DXGKMDT_OPM_ACTUAL_OUTPUT_FORMAT {
  DXGKMDT_OPM_RANDOM_NUMBER     rnRandomNumber;
  ULONG                         ulStatusFlags;
  ULONG                         ulDisplayWidth;
  ULONG                         ulDisplayHeight;
  DXGKMDT_OPM_INTERLEAVE_FORMAT ifInterleaveFormat;
  ULONG                         d3dFormat;
  ULONG                         ulFrequencyNumerator;
  ULONG                         ulFrequencyDenominator;
} DXGKMDT_OPM_ACTUAL_OUTPUT_FORMAT;