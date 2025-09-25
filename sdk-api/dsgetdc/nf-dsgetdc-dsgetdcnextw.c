DSGETDCAPI DWORD DsGetDcNextW(
  [in]            HANDLE           GetDcContextHandle,
  [out, optional] PULONG           SockAddressCount,
  [out, optional] LPSOCKET_ADDRESS *SockAddresses,
  [out, optional] LPWSTR           *DnsHostName
);