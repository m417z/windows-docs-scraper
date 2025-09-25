HRESULT GetAssemblyRefProps(
  [in]  mdAssemblyRef    mdar,
  [out] const BYTE       **ppbPublicKeyOrToken,
  [out] ULONG            *pcbPublicKeyOrToken,
  [out] LPWSTR           szName,
  [in]  ULONG            cchName,
  [out] ULONG            *pchName,
  [out] ASSEMBLYMETADATA *pMetaData,
  [out] const BYTE       **ppbHashValue,
  [out] ULONG            *pcbHashValue,
  [out] DWORD            *pdwAssemblyRefFlags
);