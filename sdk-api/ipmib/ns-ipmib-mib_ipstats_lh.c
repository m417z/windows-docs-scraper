typedef struct _MIB_IPSTATS_LH {
  union {
    DWORD                  dwForwarding;
    MIB_IPSTATS_FORWARDING Forwarding;
  };
  DWORD dwDefaultTTL;
  DWORD dwInReceives;
  DWORD dwInHdrErrors;
  DWORD dwInAddrErrors;
  DWORD dwForwDatagrams;
  DWORD dwInUnknownProtos;
  DWORD dwInDiscards;
  DWORD dwInDelivers;
  DWORD dwOutRequests;
  DWORD dwRoutingDiscards;
  DWORD dwOutDiscards;
  DWORD dwOutNoRoutes;
  DWORD dwReasmTimeout;
  DWORD dwReasmReqds;
  DWORD dwReasmOks;
  DWORD dwReasmFails;
  DWORD dwFragOks;
  DWORD dwFragFails;
  DWORD dwFragCreates;
  DWORD dwNumIf;
  DWORD dwNumAddr;
  DWORD dwNumRoutes;
} MIB_IPSTATS_LH, *PMIB_IPSTATS_LH;