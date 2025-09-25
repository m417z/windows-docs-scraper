typedef struct _TCP_OFFLOAD_STATE_DELEGATED {
  OFFLOAD_STATE_HEADER         Header;
  TCP_OFFLOAD_CONNECTION_STATE State;
  USHORT                       Flags;
  ULONG                        RcvNxt;
  ULONG                        RcvWnd;
  ULONG                        SndUna;
  ULONG                        SndNxt;
  ULONG                        SndMax;
  ULONG                        SndWnd;
  ULONG                        MaxSndWnd;
  ULONG                        SendWL1;
  ULONG                        CWnd;
  ULONG                        SsThresh;
  USHORT                       SRtt;
  USHORT                       RttVar;
  ULONG                        TsRecent;
  ULONG                        TsRecentAge;
  ULONG                        TsTime;
  ULONG                        TotalRT;
  UCHAR                        DupAckCount;
  UCHAR                        SndWndProbeCount;
  struct {
    UCHAR ProbeCount;
    ULONG TimeoutDelta;
  } KeepAlive;
  struct {
    UCHAR Count;
    ULONG TimeoutDelta;
  } Retransmit;
  union {
    struct {
      PNET_BUFFER_LIST SendDataHead;
      PNET_BUFFER_LIST SendDataTail;
    };
    ULONG SendBacklogSize;
  };
  union {
    PNET_BUFFER_LIST BufferedData;
    ULONG            ReceiveBacklogSize;
  };
  ULONG                        DWnd;
} TCP_OFFLOAD_STATE_DELEGATED, *PTCP_OFFLOAD_STATE_DELEGATED;