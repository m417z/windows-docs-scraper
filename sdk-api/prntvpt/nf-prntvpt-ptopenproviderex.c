HRESULT PTOpenProviderEx(
  [in]  PCWSTR      pszPrinterName,
        DWORD       dwMaxVersion,
        DWORD       dwPrefVersion,
  [out] HPTPROVIDER *phProvider,
  [out] DWORD       *pUsedVersion
);