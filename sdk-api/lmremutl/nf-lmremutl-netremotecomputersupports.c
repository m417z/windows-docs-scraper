NET_API_STATUS NET_API_FUNCTION NetRemoteComputerSupports(
  [in]  LPCWSTR UncServerName,
  [in]  DWORD   OptionsWanted,
  [out] LPDWORD OptionsSupported
);