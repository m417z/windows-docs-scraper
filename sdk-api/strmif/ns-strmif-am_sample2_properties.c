typedef struct tagAM_SAMPLE2_PROPERTIES {
  DWORD          cbData;
  DWORD          dwTypeSpecificFlags;
  DWORD          dwSampleFlags;
  LONG           lActual;
  REFERENCE_TIME tStart;
  REFERENCE_TIME tStop;
  DWORD          dwStreamId;
  AM_MEDIA_TYPE  *pMediaType;
  BYTE           *pbBuffer;
  LONG           cbBuffer;
} AM_SAMPLE2_PROPERTIES;