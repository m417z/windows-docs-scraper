BOOL CryptDecodeObject(
  [in]      DWORD      dwCertEncodingType,
  [in]      LPCSTR     lpszStructType,
  [in]      const BYTE *pbEncoded,
  [in]      DWORD      cbEncoded,
  [in]      DWORD      dwFlags,
  [out]     void       *pvStructInfo,
  [in, out] DWORD      *pcbStructInfo
);