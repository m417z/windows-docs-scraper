typedef struct _TCP_OFFLOAD_STATE_CACHED {
  OFFLOAD_STATE_HEADER Header;
  USHORT               Flags;
  ULONG                InitialRcvWnd;
  ULONG                RcvIndicationSize;
  UCHAR                KaProbeCount;
  ULONG                KaTimeout;
  ULONG                KaInterval;
  ULONG                MaxRT;
  ULONG                FlowLabel : 20;
  UCHAR                TtlOrHopLimit;
  UCHAR                TosOrTrafficClass;
  UCHAR                UserPriority : 3;
} TCP_OFFLOAD_STATE_CACHED, *PTCP_OFFLOAD_STATE_CACHED;