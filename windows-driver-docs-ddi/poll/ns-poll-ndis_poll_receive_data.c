typedef struct _NDIS_POLL_RECEIVE_DATA {
  ULONG           MaxNblsToIndicate;
  ULONG           Reserved1[3];
  NET_BUFFER_LIST *IndicatedNblChain;
  ULONG           NumberOfIndicatedNbls;
  ULONG           NumberOfRemainingNbls;
  ULONG           Flags;
  ULONG           Reserved2;
  void            *Reserved3[4];
} NDIS_POLL_RECEIVE_DATA;