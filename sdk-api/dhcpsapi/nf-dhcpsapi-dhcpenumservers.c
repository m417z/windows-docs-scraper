DWORD DhcpEnumServers(
  [in]  DWORD                    Flags,
  [in]  LPVOID                   IdInfo,
  [out] LPDHCP_SERVER_INFO_ARRAY *Servers,
  [in]  LPVOID                   CallbackFn,
  [in]  LPVOID                   CallbackData
);