typedef struct _TCP_ESTATS_DATA_ROD_v0 {
  ULONG64 DataBytesOut;
  ULONG64 DataSegsOut;
  ULONG64 DataBytesIn;
  ULONG64 DataSegsIn;
  ULONG64 SegsOut;
  ULONG64 SegsIn;
  ULONG   SoftErrors;
  ULONG   SoftErrorReason;
  ULONG   SndUna;
  ULONG   SndNxt;
  ULONG   SndMax;
  ULONG64 ThruBytesAcked;
  ULONG   RcvNxt;
  ULONG64 ThruBytesReceived;
} TCP_ESTATS_DATA_ROD_v0, *PTCP_ESTATS_DATA_ROD_v0;