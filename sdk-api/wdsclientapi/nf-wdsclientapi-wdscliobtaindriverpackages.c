HRESULT WDSCLIAPI WdsCliObtainDriverPackages(
  [in]  HANDLE hImage,
  [out] PWSTR  *ppwszServerName,
  [out] PWSTR  **pppwszDriverPackages,
  [out] ULONG  *pulCount
);