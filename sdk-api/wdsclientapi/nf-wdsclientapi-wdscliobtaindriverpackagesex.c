HRESULT WDSCLIAPI WdsCliObtainDriverPackagesEx(
  [in]  HANDLE hSession,
  [out] PWSTR  pwszMachineInfo,
  [out] PWSTR  *ppwszServerName,
  [out] PWSTR  **pppwszDriverPackages,
  [out] ULONG  *pulCount
);