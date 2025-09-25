DWORD DHCP_API_FUNCTION DhcpV4FailoverGetSystemTime(
  [in, optional] LPWSTR  ServerIpAddress,
  [out]          LPDWORD pTime,
                 LPDWORD pMaxAllowedDeltaTime
);