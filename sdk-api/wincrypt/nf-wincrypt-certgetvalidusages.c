BOOL CertGetValidUsages(
  [in]      DWORD          cCerts,
  [in]      PCCERT_CONTEXT *rghCerts,
  [out]     int            *cNumOIDs,
  [out]     LPSTR          *rghOIDs,
  [in, out] DWORD          *pcbOIDs
);