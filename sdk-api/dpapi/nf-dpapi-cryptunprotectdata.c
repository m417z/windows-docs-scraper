DPAPI_IMP BOOL CryptUnprotectData(
  [in]            DATA_BLOB                 *pDataIn,
  [out, optional] LPWSTR                    *ppszDataDescr,
  [in, optional]  DATA_BLOB                 *pOptionalEntropy,
                  PVOID                     pvReserved,
  [in, optional]  CRYPTPROTECT_PROMPTSTRUCT *pPromptStruct,
  [in]            DWORD                     dwFlags,
  [out]           DATA_BLOB                 *pDataOut
);