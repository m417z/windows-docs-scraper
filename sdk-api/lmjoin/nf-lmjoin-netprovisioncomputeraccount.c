NET_API_STATUS NET_API_FUNCTION NetProvisionComputerAccount(
  [in]            LPCWSTR lpDomain,
  [in]            LPCWSTR lpMachineName,
  [in, optional]  LPCWSTR lpMachineAccountOU,
  [in, optional]  LPCWSTR lpDcName,
  [in]            DWORD   dwOptions,
  [out, optional] PBYTE   *pProvisionBinData,
  [out, optional] DWORD   *pdwProvisionBinDataSize,
  [out, optional] LPWSTR  *pProvisionTextData
);