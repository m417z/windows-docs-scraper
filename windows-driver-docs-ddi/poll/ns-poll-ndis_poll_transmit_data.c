typedef struct _NDIS_POLL_TRANSMIT_DATA {
  ULONG           MaxNblsToComplete;
  ULONG           Reserved1[3];
  NET_BUFFER_LIST *CompletedNblChain;
  ULONG           NumberOfCompletedNbls;
  ULONG           NumberOfRemainingNbls;
  ULONG           SendCompleteFlags;
  ULONG           Reserved2;
  void            *Reserved3[4];
} NDIS_POLL_TRANSMIT_DATA;