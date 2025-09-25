DSGETDCAPI DWORD DsAddressToSiteNamesExA(
  [in, optional] LPCSTR          ComputerName,
  [in]           DWORD           EntryCount,
  [in]           PSOCKET_ADDRESS SocketAddresses,
  [out]          LPSTR           **SiteNames,
  [out]          LPSTR           **SubnetNames
);