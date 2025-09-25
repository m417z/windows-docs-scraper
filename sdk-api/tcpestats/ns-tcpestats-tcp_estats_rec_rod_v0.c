typedef struct _TCP_ESTATS_REC_ROD_v0 {
  ULONG  CurRwinSent;
  ULONG  MaxRwinSent;
  ULONG  MinRwinSent;
  ULONG  LimRwin;
  ULONG  DupAckEpisodes;
  ULONG  DupAcksOut;
  ULONG  CeRcvd;
  ULONG  EcnSent;
  ULONG  EcnNoncesRcvd;
  ULONG  CurReasmQueue;
  ULONG  MaxReasmQueue;
  SIZE_T CurAppRQueue;
  SIZE_T MaxAppRQueue;
  UCHAR  WinScaleSent;
} TCP_ESTATS_REC_ROD_v0, *PTCP_ESTATS_REC_ROD_v0;