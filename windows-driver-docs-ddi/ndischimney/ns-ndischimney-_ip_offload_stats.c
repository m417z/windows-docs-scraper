typedef struct _IP_OFFLOAD_STATS {
  ULONG64 InReceives;
  ULONG64 InOctets;
  ULONG64 InDelivers;
  ULONG64 OutRequests;
  ULONG64 OutOctets;
  ULONG   InHeaderErrors;
  ULONG   InTruncatedPackets;
  ULONG   InDiscards;
  ULONG   OutDiscards;
  ULONG   OutNoRoutes;
} IP_OFFLOAD_STATS, *PIP_OFFLOAD_STATS;