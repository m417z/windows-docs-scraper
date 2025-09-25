typedef struct _MIB_TCPSTATS2 {
  TCP_RTO_ALGORITHM RtoAlgorithm;
  DWORD             dwRtoMin;
  DWORD             dwRtoMax;
  DWORD             dwMaxConn;
  DWORD             dwActiveOpens;
  DWORD             dwPassiveOpens;
  DWORD             dwAttemptFails;
  DWORD             dwEstabResets;
  DWORD             dwCurrEstab;
  DWORD64           dw64InSegs;
  DWORD64           dw64OutSegs;
  DWORD             dwRetransSegs;
  DWORD             dwInErrs;
  DWORD             dwOutRsts;
  DWORD             dwNumConns;
} MIB_TCPSTATS2, *PMIB_TCPSTATS2;