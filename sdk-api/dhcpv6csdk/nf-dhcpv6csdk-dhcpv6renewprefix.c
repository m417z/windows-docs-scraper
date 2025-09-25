DWORD Dhcpv6RenewPrefix(
  [in]      LPWSTR                         adapterName,
  [in]      LPDHCPV6CAPI_CLASSID           pclassId,
  [in, out] LPDHCPV6PrefixLeaseInformation prefixleaseInfo,
  [out]     DWORD                          *pdwTimeToWait,
  [in]      DWORD                          bValidatePrefix
);