DPAPI_IMP BOOL CryptProtectData(
  [in]           DATA_BLOB                 *pDataIn,
  [in, optional] LPCWSTR                   szDataDescr,
  [in, optional] DATA_BLOB                 *pOptionalEntropy,
  [in]           PVOID                     pvReserved,
  [in, optional] CRYPTPROTECT_PROMPTSTRUCT *pPromptStruct,
  [in]           DWORD                     dwFlags,
  [out]          DATA_BLOB                 *pDataOut
);