typedef struct NLM_SIMULATED_PROFILE_INFO {
  WCHAR               ProfileName[256];
  NLM_CONNECTION_COST cost;
  DWORD               UsageInMegabytes;
  DWORD               DataLimitInMegabytes;
} NLM_SIMULATED_PROFILE_INFO;