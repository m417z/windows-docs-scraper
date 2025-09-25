typedef struct _PIPE_TERMINATION {
  ULONG                     Flags;
  ULONG                     OutsideFactors;
  ULONG                     Weigth;
  KS_FRAMING_RANGE          PhysicalRange;
  KS_FRAMING_RANGE_WEIGHTED OptimalRange;
  KS_COMPRESSION            Compression;
} PIPE_TERMINATION;