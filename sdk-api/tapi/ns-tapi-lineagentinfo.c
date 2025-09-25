typedef struct lineagentinfo_tag {
  DWORD    dwTotalSize;
  DWORD    dwNeededSize;
  DWORD    dwUsedSize;
  DWORD    dwAgentState;
  DWORD    dwNextAgentState;
  DWORD    dwMeasurementPeriod;
  CURRENCY cyOverallCallRate;
  DWORD    dwNumberOfACDCalls;
  DWORD    dwNumberOfIncomingCalls;
  DWORD    dwNumberOfOutgoingCalls;
  DWORD    dwTotalACDTalkTime;
  DWORD    dwTotalACDCallTime;
  DWORD    dwTotalACDWrapUpTime;
} LINEAGENTINFO, *LPLINEAGENTINFO;