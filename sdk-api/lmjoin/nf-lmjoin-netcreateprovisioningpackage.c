NET_API_STATUS NET_API_FUNCTION NetCreateProvisioningPackage(
  [in]            PNETSETUP_PROVISIONING_PARAMS pProvisioningParams,
  [out, optional] PBYTE                         *ppPackageBinData,
  [out, optional] DWORD                         *pdwPackageBinDataSize,
  [out, optional] LPWSTR                        *ppPackageTextData
);