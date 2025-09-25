PCCERT_CONTEXT CertCreateSelfSignCertificate(
  [in, optional] HCRYPTPROV_OR_NCRYPT_KEY_HANDLE hCryptProvOrNCryptKey,
  [in]           PCERT_NAME_BLOB                 pSubjectIssuerBlob,
  [in]           DWORD                           dwFlags,
  [in, optional] PCRYPT_KEY_PROV_INFO            pKeyProvInfo,
  [in, optional] PCRYPT_ALGORITHM_IDENTIFIER     pSignatureAlgorithm,
  [in, optional] PSYSTEMTIME                     pStartTime,
  [in, optional] PSYSTEMTIME                     pEndTime,
  [optional]     PCERT_EXTENSIONS                pExtensions
);