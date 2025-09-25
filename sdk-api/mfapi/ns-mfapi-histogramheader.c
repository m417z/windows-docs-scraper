typedef struct tagHistogramHeader {
  ULONG         Size;
  ULONG         Bins;
  ULONG         FourCC;
  ULONG         ChannelMasks;
  HistogramGrid Grid;
} HistogramHeader;