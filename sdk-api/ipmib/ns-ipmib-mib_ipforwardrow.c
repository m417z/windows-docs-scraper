typedef struct _MIB_IPFORWARDROW {
  DWORD    dwForwardDest;
  DWORD    dwForwardMask;
  DWORD    dwForwardPolicy;
  DWORD    dwForwardNextHop;
  IF_INDEX dwForwardIfIndex;
  union {
    DWORD              dwForwardType;
    MIB_IPFORWARD_TYPE ForwardType;
  };
  union {
    DWORD               dwForwardProto;
    MIB_IPFORWARD_PROTO ForwardProto;
  };
  DWORD    dwForwardAge;
  DWORD    dwForwardNextHopAS;
  DWORD    dwForwardMetric1;
  DWORD    dwForwardMetric2;
  DWORD    dwForwardMetric3;
  DWORD    dwForwardMetric4;
  DWORD    dwForwardMetric5;
} MIB_IPFORWARDROW, *PMIB_IPFORWARDROW;