typedef struct _BDA_PID_MAP {
  MEDIA_SAMPLE_CONTENT MediaSampleContent;
  ULONG                ulcPIDs;
  ULONG                aulPIDs[MIN_DIMENSION];
} BDA_PID_MAP, *PBDA_PID_MAP;