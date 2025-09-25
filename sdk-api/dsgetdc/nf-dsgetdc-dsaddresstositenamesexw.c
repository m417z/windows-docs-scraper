DSGETDCAPI DWORD DsAddressToSiteNamesExW(
  [in, optional] LPCWSTR         ComputerName,
  [in]           DWORD           EntryCount,
  [in]           PSOCKET_ADDRESS SocketAddresses,
  [out]          LPWSTR          **SiteNames,
  [out]          LPWSTR          **SubnetNames
);