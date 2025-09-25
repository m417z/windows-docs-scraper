BOOL CertVerifyCRLRevocation(
  [in] DWORD        dwCertEncodingType,
  [in] PCERT_INFO   pCertId,
  [in] DWORD        cCrlInfo,
  [in] PCRL_INFO [] rgpCrlInfo
);