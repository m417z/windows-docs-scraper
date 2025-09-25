BOOL CryptEncodeObject(
  [in]      DWORD      dwCertEncodingType,
  [in]      LPCSTR     lpszStructType,
  [in]      const void *pvStructInfo,
  [out]     BYTE       *pbEncoded,
  [in, out] DWORD      *pcbEncoded
);