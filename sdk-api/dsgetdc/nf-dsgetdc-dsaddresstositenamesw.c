DSGETDCAPI DWORD DsAddressToSiteNamesW(
  [in, optional] LPCWSTR         ComputerName,
  [in]           DWORD           EntryCount,
  [in]           PSOCKET_ADDRESS SocketAddresses,
  [out]          LPWSTR          **SiteNames
);