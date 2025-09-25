typedef union _timecode {
  struct {
    WORD  wFrameRate;
    WORD  wFrameFract;
    DWORD dwFrames;
  };
  DWORDLONG qw;
} TIMECODE;