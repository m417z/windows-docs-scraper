typedef union _NET_LUID_LH {
  ULONG64 Value;
  struct {
    ULONG64 Reserved : 24;
    ULONG64 NetLuidIndex : 24;
    ULONG64 IfType : 16;
  } Info;
} NET_LUID_LH, *PNET_LUID_LH;