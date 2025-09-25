DSGETDCAPI DWORD DsGetDcNextA(
  [in]            HANDLE           GetDcContextHandle,
  [out, optional] PULONG           SockAddressCount,
  [out, optional] LPSOCKET_ADDRESS *SockAddresses,
  [out, optional] LPSTR            *DnsHostName
);