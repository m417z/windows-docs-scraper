typedef struct _WINHTTP_CERTIFICATE_INFO {
  FILETIME ftExpiry;
  FILETIME ftStart;
  LPWSTR   lpszSubjectInfo;
  LPWSTR   lpszIssuerInfo;
  LPWSTR   lpszProtocolName;
  LPWSTR   lpszSignatureAlgName;
  LPWSTR   lpszEncryptionAlgName;
  DWORD    dwKeySize;
} WINHTTP_CERTIFICATE_INFO, *PWINHTTP_CERTIFICATE_INFO;