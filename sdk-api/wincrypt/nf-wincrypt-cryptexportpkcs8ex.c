BOOL CryptExportPKCS8Ex(
  [in]            CRYPT_PKCS8_EXPORT_PARAMS *psExportParams,
  [in]            DWORD                     dwFlags,
  [in, optional]  void                      *pvAuxInfo,
  [out, optional] BYTE                      *pbPrivateKeyBlob,
  [in, out]       DWORD                     *pcbPrivateKeyBlob
);