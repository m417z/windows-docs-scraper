typedef struct _MIB_TCPSTATS_W2K {
  DWORD dwRtoAlgorithm;
  DWORD dwRtoMin;
  DWORD dwRtoMax;
  DWORD dwMaxConn;
  DWORD dwActiveOpens;
  DWORD dwPassiveOpens;
  DWORD dwAttemptFails;
  DWORD dwEstabResets;
  DWORD dwCurrEstab;
  DWORD dwInSegs;
  DWORD dwOutSegs;
  DWORD dwRetransSegs;
  DWORD dwInErrs;
  DWORD dwOutRsts;
  DWORD dwNumConns;
} MIB_TCPSTATS_W2K, *PMIB_TCPSTATS_W2K;