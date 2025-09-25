BOOL CryptInstallOIDFunctionAddress(
  [in] HMODULE                       hModule,
  [in] DWORD                         dwEncodingType,
  [in] LPCSTR                        pszFuncName,
  [in] DWORD                         cFuncEntry,
  [in] const CRYPT_OID_FUNC_ENTRY [] rgFuncEntry,
  [in] DWORD                         dwFlags
);