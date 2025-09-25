BOOL CryptAcquireCertificatePrivateKey(
  [in]           PCCERT_CONTEXT                  pCert,
  [in]           DWORD                           dwFlags,
  [in, optional] void                            *pvParameters,
  [out]          HCRYPTPROV_OR_NCRYPT_KEY_HANDLE *phCryptProvOrNCryptKey,
  [out]          DWORD                           *pdwKeySpec,
  [out]          BOOL                            *pfCallerFreeProvOrNCryptKey
);