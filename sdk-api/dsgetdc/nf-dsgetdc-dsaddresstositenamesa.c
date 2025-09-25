DSGETDCAPI DWORD DsAddressToSiteNamesA(
  [in, optional] LPCSTR          ComputerName,
  [in]           DWORD           EntryCount,
  [in]           PSOCKET_ADDRESS SocketAddresses,
  [out]          LPSTR           **SiteNames
);