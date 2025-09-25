DWORD DhcpGetClassInfo(
  [in]  LPWSTR            ServerIpAddress,
  [in]  DWORD             ReservedMustBeZero,
  [in]  LPDHCP_CLASS_INFO PartialClassInfo,
  [out] LPDHCP_CLASS_INFO *FilledClassInfo
);