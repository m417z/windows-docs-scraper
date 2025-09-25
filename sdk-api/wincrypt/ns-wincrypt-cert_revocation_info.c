typedef struct _CERT_REVOCATION_INFO {
  DWORD                     cbSize;
  DWORD                     dwRevocationResult;
  LPCSTR                    pszRevocationOid;
  LPVOID                    pvOidSpecificInfo;
  BOOL                      fHasFreshnessTime;
  DWORD                     dwFreshnessTime;
  PCERT_REVOCATION_CRL_INFO pCrlInfo;
} CERT_REVOCATION_INFO, *PCERT_REVOCATION_INFO;