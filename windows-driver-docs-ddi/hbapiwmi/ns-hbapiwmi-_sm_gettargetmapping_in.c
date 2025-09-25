typedef struct _SM_GetTargetMapping_IN {
  UCHAR HbaPortWWN[8];
  UCHAR DomainPortWWN[8];
  ULONG InEntryCount;
} SM_GetTargetMapping_IN, *PSM_GetTargetMapping_IN;