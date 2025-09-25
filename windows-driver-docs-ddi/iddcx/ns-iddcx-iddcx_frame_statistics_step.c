struct IDDCX_FRAME_STATISTICS_STEP {
  UINT                             Size;
  IDDCX_FRAME_STATISTICS_STEP_TYPE Type;
  UINT64                           QpcTime;
  UINT32                           Data[2];
};