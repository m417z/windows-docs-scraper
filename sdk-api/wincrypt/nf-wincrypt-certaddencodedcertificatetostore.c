BOOL CertAddEncodedCertificateToStore(
  [in]            HCERTSTORE     hCertStore,
  [in]            DWORD          dwCertEncodingType,
  [in]            const BYTE     *pbCertEncoded,
  [in]            DWORD          cbCertEncoded,
  [in]            DWORD          dwAddDisposition,
  [out, optional] PCCERT_CONTEXT *ppCertContext
);