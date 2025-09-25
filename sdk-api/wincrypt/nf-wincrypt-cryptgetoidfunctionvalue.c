BOOL CryptGetOIDFunctionValue(
  [in]      DWORD   dwEncodingType,
  [in]      LPCSTR  pszFuncName,
  [in]      LPCSTR  pszOID,
  [in]      LPCWSTR pwszValueName,
  [out]     DWORD   *pdwValueType,
  [out]     BYTE    *pbValueData,
  [in, out] DWORD   *pcbValueData
);