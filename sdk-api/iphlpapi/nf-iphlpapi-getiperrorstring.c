IPHLPAPI_DLL_LINKAGE DWORD GetIpErrorString(
  [in]      IP_STATUS ErrorCode,
  [out]     PWSTR     Buffer,
  [in, out] PDWORD    Size
);