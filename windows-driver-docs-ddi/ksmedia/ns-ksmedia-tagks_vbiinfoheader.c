typedef struct tagKS_VBIINFOHEADER {
  ULONG StartLine;
  ULONG EndLine;
  ULONG SamplingFrequency;
  ULONG MinLineStartTime;
  ULONG MaxLineStartTime;
  ULONG ActualLineStartTime;
  ULONG ActualLineEndTime;
  ULONG VideoStandard;
  ULONG SamplesPerLine;
  ULONG StrideInBytes;
  ULONG BufferSize;
} KS_VBIINFOHEADER, *PKS_VBIINFOHEADER;