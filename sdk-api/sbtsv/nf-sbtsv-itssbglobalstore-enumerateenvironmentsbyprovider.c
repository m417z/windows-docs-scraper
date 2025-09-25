HRESULT EnumerateEnvironmentsByProvider(
  [in]      BSTR                   ProviderName,
  [in, out] DWORD                  *pdwCount,
  [out]     ITsSbEnvironment ** [] ppVal
);