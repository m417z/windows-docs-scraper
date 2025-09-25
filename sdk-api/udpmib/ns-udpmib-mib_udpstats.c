typedef struct _MIB_UDPSTATS {
  DWORD dwInDatagrams;
  DWORD dwNoPorts;
  DWORD dwInErrors;
  DWORD dwOutDatagrams;
  DWORD dwNumAddrs;
} MIB_UDPSTATS, *PMIB_UDPSTATS;