DWORD ClusterDecrypt(
  [in]  HCLUSCRYPTPROVIDER hClusCryptProvider,
  [in]  PBYTE              pCryptInput,
  [in]  DWORD              cbCryptInput,
  [out] PBYTE              *ppCryptOutput,
  [out] PDWORD             pcbCryptOutput
);