typedef struct _AddTarget_IN {
  UCHAR HbaPortWWN[8];
  UCHAR DiscoveredPortWWN[8];
  ULONG AllTargets;
} AddTarget_IN, *PAddTarget_IN;