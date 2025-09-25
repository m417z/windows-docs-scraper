DRMEXPORT HRESULT UDAPICALL DRMEnumerateLicense(
  [in]      DRMHSESSION hSession,
  [in]      UINT        uFlags,
  [in]      UINT        uIndex,
  [in, out] BOOL        *pfSharedFlag,
  [in, out] UINT        *puCertificateDataLen,
  [out]     PWSTR       wszCertificateData
);