BOOL CryptExportPKCS8(
  [in]            HCRYPTPROV hCryptProv,
  [in]            DWORD      dwKeySpec,
  [in]            LPSTR      pszPrivateKeyObjId,
  [in]            DWORD      dwFlags,
  [in, optional]  void       *pvAuxInfo,
  [out, optional] BYTE       *pbPrivateKeyBlob,
  [in, out]       DWORD      *pcbPrivateKeyBlob
);