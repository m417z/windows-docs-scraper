BOOL CryptEnumOIDFunction(
  [in] DWORD                   dwEncodingType,
  [in] LPCSTR                  pszFuncName,
  [in] LPCSTR                  pszOID,
  [in] DWORD                   dwFlags,
  [in] void                    *pvArg,
  [in] PFN_CRYPT_ENUM_OID_FUNC pfnEnumOIDFunc
);