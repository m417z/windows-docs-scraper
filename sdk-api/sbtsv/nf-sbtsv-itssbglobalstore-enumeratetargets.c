HRESULT EnumerateTargets(
  [in]      BSTR              ProviderName,
  [in]      BSTR              FarmName,
  [in]      BSTR              EnvName,
  [in, out] DWORD             *pdwCount,
  [out]     ITsSbTarget ** [] pVal
);