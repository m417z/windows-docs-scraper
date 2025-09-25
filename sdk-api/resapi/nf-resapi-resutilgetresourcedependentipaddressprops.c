DWORD ResUtilGetResourceDependentIPAddressProps(
  [in]      HRESOURCE hResource,
  [out]     LPWSTR    pszAddress,
  [in, out] DWORD     *pcchAddress,
  [out]     LPWSTR    pszSubnetMask,
  [in, out] DWORD     *pcchSubnetMask,
  [out]     LPWSTR    pszNetwork,
  [in, out] DWORD     *pcchNetwork
);