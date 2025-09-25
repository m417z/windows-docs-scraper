typedef struct _TCP_OFFLOAD_STATS {
  ULONG64 InSegments;
  ULONG64 OutSegments;
  ULONG   CurrentlyEstablished;
  ULONG   ResetEstablished;
  ULONG   RetransmittedSegments;
  ULONG   InErrors;
  ULONG   OutResets;
} TCP_OFFLOAD_STATS, *PTCP_OFFLOAD_STATS;