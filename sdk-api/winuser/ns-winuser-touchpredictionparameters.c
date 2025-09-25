typedef struct tagTouchPredictionParameters {
  UINT cbSize;
  UINT dwLatency;
  UINT dwSampleTime;
  UINT bUseHWTimeStamp;
} TOUCHPREDICTIONPARAMETERS, *PTOUCHPREDICTIONPARAMETERS;