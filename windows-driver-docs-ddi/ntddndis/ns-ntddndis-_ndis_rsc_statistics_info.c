typedef struct _NDIS_RSC_STATISTICS_INFO {
  NDIS_OBJECT_HEADER Header;
  ULONG64            CoalescedPkts;
  ULONG64            CoalescedOctets;
  ULONG64            CoalesceEvents;
  ULONG64            Aborts;
} NDIS_RSC_STATISTICS_INFO, *PNDIS_RSC_STATISTICS_INFO;