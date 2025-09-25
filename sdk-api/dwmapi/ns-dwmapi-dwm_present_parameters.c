typedef struct _DWM_PRESENT_PARAMETERS {
  UINT32                    cbSize;
  BOOL                      fQueue;
  DWM_FRAME_COUNT           cRefreshStart;
  UINT                      cBuffer;
  BOOL                      fUseSourceRate;
  UNSIGNED_RATIO            rateSource;
  UINT                      cRefreshesPerFrame;
  DWM_SOURCE_FRAME_SAMPLING eSampling;
} DWM_PRESENT_PARAMETERS;