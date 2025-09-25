typedef struct linequeueinfo_tag {
  DWORD dwTotalSize;
  DWORD dwNeededSize;
  DWORD dwUsedSize;
  DWORD dwMeasurementPeriod;
  DWORD dwTotalCallsQueued;
  DWORD dwCurrentCallsQueued;
  DWORD dwTotalCallsAbandoned;
  DWORD dwTotalCallsFlowedIn;
  DWORD dwTotalCallsFlowedOut;
  DWORD dwLongestEverWaitTime;
  DWORD dwCurrentLongestWaitTime;
  DWORD dwAverageWaitTime;
  DWORD dwFinalDisposition;
} LINEQUEUEINFO, *LPLINEQUEUEINFO;