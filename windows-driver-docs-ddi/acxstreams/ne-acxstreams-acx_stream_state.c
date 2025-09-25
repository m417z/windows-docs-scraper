typedef enum _ACX_STREAM_STATE {
  AcxStreamStateStop,
  AcxStreamStateAcquire,
  AcxStreamStatePause,
  AcxStreamStateRun,
  AcxStreamStateMaximum
} ACX_STREAM_STATE, *PACX_STREAM_STATE;