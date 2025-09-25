typedef struct _NDIS_PD_FILTER_PARAMETERS {
  NDIS_OBJECT_HEADER     Header;
  ULONG                  Flags;
  NDIS_GFP_PROFILE_ID    MatchProfileId;
  ULONG                  Priority;
  NDIS_PD_COUNTER_HANDLE CounterHandle;
  NDIS_PD_QUEUE          *TargetReceiveQueue;
  ULONG64                RxFilterContext;
  PUCHAR                 HeaderGroupMatchArray;
  ULONG                  HeaderGroupMatchArrayNumElements;
  ULONG                  HeaderGroupMatchArrayElementSize;
  ULONG                  HeaderGroupMatchArrayTotalSize;
} NDIS_PD_FILTER_PARAMETERS;