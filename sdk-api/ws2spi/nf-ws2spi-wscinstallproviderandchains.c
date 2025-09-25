int WSCInstallProviderAndChains(
  [in]            LPGUID              lpProviderId,
  [in]            const LPWSTR        lpszProviderDllPath,
  [in]            const LPWSTR        lpszLspName,
  [in]            DWORD               dwServiceFlags,
  [in]            LPWSAPROTOCOL_INFOW lpProtocolInfoList,
  [in]            DWORD               dwNumberOfEntries,
  [out, optional] LPDWORD             lpdwCatalogEntryId,
  [out]           LPINT               lpErrno
);