typedef struct _OPM_ACTUAL_OUTPUT_FORMAT {
  OPM_RANDOM_NUMBER  rnRandomNumber;
  ULONG              ulStatusFlags;
  ULONG              ulDisplayWidth;
  ULONG              ulDisplayHeight;
  DXVA2_SampleFormat dsfSampleInterleaveFormat;
  D3DFORMAT          d3dFormat;
  ULONG              ulFrequencyNumerator;
  ULONG              ulFrequencyDenominator;
} OPM_ACTUAL_OUTPUT_FORMAT;