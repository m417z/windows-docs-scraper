BOOL CryptFormatObject(
  [in]      DWORD      dwCertEncodingType,
  [in]      DWORD      dwFormatType,
  [in]      DWORD      dwFormatStrType,
  [in]      void       *pFormatStruct,
  [in]      LPCSTR     lpszStructType,
  [in]      const BYTE *pbEncoded,
  [in]      DWORD      cbEncoded,
  [out]     void       *pbFormat,
  [in, out] DWORD      *pcbFormat
);