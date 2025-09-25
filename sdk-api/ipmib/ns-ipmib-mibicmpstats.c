typedef struct _MIBICMPSTATS {
  DWORD dwMsgs;
  DWORD dwErrors;
  DWORD dwDestUnreachs;
  DWORD dwTimeExcds;
  DWORD dwParmProbs;
  DWORD dwSrcQuenchs;
  DWORD dwRedirects;
  DWORD dwEchos;
  DWORD dwEchoReps;
  DWORD dwTimestamps;
  DWORD dwTimestampReps;
  DWORD dwAddrMasks;
  DWORD dwAddrMaskReps;
} MIBICMPSTATS, *PMIBICMPSTATS;