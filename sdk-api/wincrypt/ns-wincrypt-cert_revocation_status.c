typedef struct _CERT_REVOCATION_STATUS {
  DWORD cbSize;
  DWORD dwIndex;
  DWORD dwError;
  DWORD dwReason;
  BOOL  fHasFreshnessTime;
  DWORD dwFreshnessTime;
} CERT_REVOCATION_STATUS, *PCERT_REVOCATION_STATUS;