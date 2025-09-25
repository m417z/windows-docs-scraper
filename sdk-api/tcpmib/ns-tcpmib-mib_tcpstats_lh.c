typedef struct _MIB_TCPSTATS_LH {
  union {
    DWORD             dwRtoAlgorithm;
    TCP_RTO_ALGORITHM RtoAlgorithm;
  };
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
} MIB_TCPSTATS_LH, *PMIB_TCPSTATS_LH;