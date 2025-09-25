BOOL CryptEncodeObjectEx(
  [in]      DWORD              dwCertEncodingType,
  [in]      LPCSTR             lpszStructType,
  [in]      const void         *pvStructInfo,
  [in]      DWORD              dwFlags,
  [in]      PCRYPT_ENCODE_PARA pEncodePara,
  [out]     void               *pvEncoded,
  [in, out] DWORD              *pcbEncoded
);