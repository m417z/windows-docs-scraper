LPDHCP_DELETE_CLIENT LpdhcpDeleteClient;

DWORD LpdhcpDeleteClient(
  [in] DWORD IpAddress,
  [in] LPBYTE HwAddress,
  [in] ULONG HwAddressLength,
  [in] DWORD Reserved,
  [in] DWORD ClientType
)
{...}