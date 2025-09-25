typedef struct {
  FILETIME ftExpiry;
  FILETIME ftStart;
  LPTSTR   lpszSubjectInfo;
  LPTSTR   lpszIssuerInfo;
  LPTSTR   lpszProtocolName;
  LPTSTR   lpszSignatureAlgName;
  LPTSTR   lpszEncryptionAlgName;
  DWORD    dwKeySize;
} INTERNET_CERTIFICATE_INFO, *LPINTERNET_CERTIFICATE_INFO;