NET_API_STATUS NET_API_FUNCTION NetRequestProvisioningPackageInstall(
  [in] BYTE    *pPackageBinData,
  [in] DWORD   dwPackageBinDataSize,
  [in] DWORD   dwProvisionOptions,
  [in] LPCWSTR lpWindowsPath,
       PVOID   pvReserved
);