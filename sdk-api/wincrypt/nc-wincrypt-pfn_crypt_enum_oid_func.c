PFN_CRYPT_ENUM_OID_FUNC PfnCryptEnumOidFunc;

BOOL PfnCryptEnumOidFunc(
  [in] DWORD dwEncodingType,
       LPCSTR pszFuncName,
  [in] LPCSTR pszOID,
  [in] DWORD cValue,
       const DWORD rgdwValueType[],
       LPCWSTR const rgpwszValueName[],
       const BYTE * const rgpbValueData[],
       const DWORD rgcbValueData[],
  [in] void *pvArg
)
{...}