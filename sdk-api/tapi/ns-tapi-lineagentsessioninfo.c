typedef struct lineagentsessioninfo_tag {
  DWORD    dwTotalSize;
  DWORD    dwNeededSize;
  DWORD    dwUsedSize;
  DWORD    dwAgentSessionState;
  DWORD    dwNextAgentSessionState;
  DATE     dateSessionStartTime;
  DWORD    dwSessionDuration;
  DWORD    dwNumberOfCalls;
  DWORD    dwTotalTalkTime;
  DWORD    dwAverageTalkTime;
  DWORD    dwTotalCallTime;
  DWORD    dwAverageCallTime;
  DWORD    dwTotalWrapUpTime;
  DWORD    dwAverageWrapUpTime;
  CURRENCY cyACDCallRate;
  DWORD    dwLongestTimeToAnswer;
  DWORD    dwAverageTimeToAnswer;
} LINEAGENTSESSIONINFO, *LPLINEAGENTSESSIONINFO;