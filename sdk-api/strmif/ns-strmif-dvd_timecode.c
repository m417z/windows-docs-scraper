typedef struct tagDVD_TIMECODE {
  ULONG Hours1 : 4;
  ULONG Hours10 : 4;
  ULONG Minutes1 : 4;
  ULONG Minutes10 : 4;
  ULONG Seconds1 : 4;
  ULONG Seconds10 : 4;
  ULONG Frames1 : 4;
  ULONG Frames10 : 2;
  ULONG FrameRateCode : 2;
} DVD_TIMECODE;