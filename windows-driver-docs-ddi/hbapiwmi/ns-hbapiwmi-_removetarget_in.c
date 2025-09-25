typedef struct _RemoveTarget_IN {
  UCHAR HbaPortWWN[8];
  UCHAR DiscoveredPortWWN[8];
  ULONG AllTargets;
} RemoveTarget_IN, *PRemoveTarget_IN;