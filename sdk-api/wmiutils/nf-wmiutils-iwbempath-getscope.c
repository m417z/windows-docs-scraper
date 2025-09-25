HRESULT GetScope(
  [in]      ULONG            uIndex,
  [in, out] ULONG            *puClassNameBufSize,
  [out]     LPWSTR           pszClass,
  [out]     IWbemPathKeyList **pKeyList
);