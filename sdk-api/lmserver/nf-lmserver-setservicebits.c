BOOL NET_API_FUNCTION SetServiceBits(
  [in] SERVICE_STATUS_HANDLE hServiceStatus,
  [in] DWORD                 dwServiceBits,
  [in] BOOL                  bSetBitsOn,
  [in] BOOL                  bUpdateImmediately
);