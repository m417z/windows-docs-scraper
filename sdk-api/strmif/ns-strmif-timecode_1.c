typedef union _timecode {
  struct {
    WORD  wFrameRate;
    WORD  wFrameFract;
    DWORD dwFrames;
  } DUMMYSTRUCTNAME;
  DWORDLONG qw;
} TIMECODE;