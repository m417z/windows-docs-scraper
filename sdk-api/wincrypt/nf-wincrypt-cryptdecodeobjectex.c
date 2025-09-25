BOOL CryptDecodeObjectEx(
  [in]      DWORD              dwCertEncodingType,
  [in]      LPCSTR             lpszStructType,
  [in]      const BYTE         *pbEncoded,
  [in]      DWORD              cbEncoded,
  [in]      DWORD              dwFlags,
  [in]      PCRYPT_DECODE_PARA pDecodePara,
  [out]     void               *pvStructInfo,
  [in, out] DWORD              *pcbStructInfo
);