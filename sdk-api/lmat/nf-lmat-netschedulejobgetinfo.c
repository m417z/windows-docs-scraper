NET_API_STATUS NET_API_FUNCTION NetScheduleJobGetInfo(
  [in, optional] LPCWSTR Servername,
  [in]           DWORD   JobId,
  [out]          LPBYTE  *PointerToBuffer
);