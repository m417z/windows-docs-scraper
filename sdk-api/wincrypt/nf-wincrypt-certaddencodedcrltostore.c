BOOL CertAddEncodedCRLToStore(
  [in]            HCERTSTORE    hCertStore,
  [in]            DWORD         dwCertEncodingType,
  [in]            const BYTE    *pbCrlEncoded,
  [in]            DWORD         cbCrlEncoded,
  [in]            DWORD         dwAddDisposition,
  [out, optional] PCCRL_CONTEXT *ppCrlContext
);