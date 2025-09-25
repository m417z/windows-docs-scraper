typedef struct _MIB_UDPSTATS2 {
  DWORD64 dw64InDatagrams;
  DWORD   dwNoPorts;
  DWORD   dwInErrors;
  DWORD64 dw64OutDatagrams;
  DWORD   dwNumAddrs;
} MIB_UDPSTATS2, *PMIB_UDPSTATS2;