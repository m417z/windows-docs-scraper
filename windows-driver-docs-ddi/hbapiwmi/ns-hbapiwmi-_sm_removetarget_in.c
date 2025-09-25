typedef struct _SM_RemoveTarget_IN {
  UCHAR HbaPortWWN[8];
  UCHAR DiscoveredPortWWN[8];
  UCHAR DomainPortWWN[8];
  ULONG AllTargets;
} SM_RemoveTarget_IN, *PSM_RemoveTarget_IN;