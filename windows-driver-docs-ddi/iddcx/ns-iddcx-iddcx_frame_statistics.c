struct IDDCX_FRAME_STATISTICS {
  UINT                         Size;
  UINT                         PresentationFrameNumber;
  IDDCX_FRAME_STATUS           FrameStatus;
  UINT                         ReEncodeNumber;
  UINT                         FrameSliceTotal;
  UINT                         CurrentSlice;
  UINT64                       FrameAcquireQpcTime;
  UINT                         FrameProcessingStepsCount;
  IDDCX_FRAME_STATISTICS_STEP  *pFrameProcessingStep;
  UINT64                       SendStartQpcTime;
  UINT64                       SendStopQpcTime;
  UINT64                       SendCompleteQpcTime;
  IDDCX_FRAME_STATISTICS_FLAGS Flags;
  UINT                         ProcessedPixelCount;
  UINT                         FrameSizeInBytes;
};