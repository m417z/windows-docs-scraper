HRESULT GetAssemblyProps(
  [in]  mdAssembly       mda,
  [out] const BYTE       **ppbPublicKey,
  [out] ULONG            *pcbPublicKey,
  [out] ULONG            *pulHashAlgId,
  [out] LPWSTR           szName,
  [in]  ULONG            cchName,
  [out] ULONG            *pchName,
  [out] ASSEMBLYMETADATA *pMetaData,
  [out] DWORD            *pdwAssemblyFlags
);