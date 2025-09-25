typedef struct _SM_GetTargetMapping_OUT {
  ULONG              HBAStatus;
  ULONG              TotalEntryCount;
  ULONG              OutEntryCount;
  MS_SMHBA_SCSIENTRY Entry[1];
} SM_GetTargetMapping_OUT, *PSM_GetTargetMapping_OUT;