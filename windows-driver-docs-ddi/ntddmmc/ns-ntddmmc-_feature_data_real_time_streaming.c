typedef struct _FEATURE_DATA_REAL_TIME_STREAMING {
  FEATURE_HEADER Header;
  UCHAR          StreamRecording : 1;
  UCHAR          WriteSpeedInGetPerf : 1;
  UCHAR          WriteSpeedInMP2A : 1;
  UCHAR          SetCDSpeed : 1;
  UCHAR          ReadBufferCapacityBlock : 1;
  UCHAR          Reserved1 : 3;
  UCHAR          Reserved2[3];
} FEATURE_DATA_REAL_TIME_STREAMING, *PFEATURE_DATA_REAL_TIME_STREAMING;