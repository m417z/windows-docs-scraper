typedef struct _HTTP_SERVICE_CONFIG_SSL_PARAM {
  ULONG SslHashLength;
  PVOID pSslHash;
  GUID  AppId;
  PWSTR pSslCertStoreName;
  DWORD DefaultCertCheckMode;
  DWORD DefaultRevocationFreshnessTime;
  DWORD DefaultRevocationUrlRetrievalTimeout;
  PWSTR pDefaultSslCtlIdentifier;
  PWSTR pDefaultSslCtlStoreName;
  DWORD DefaultFlags;
} HTTP_SERVICE_CONFIG_SSL_PARAM, *PHTTP_SERVICE_CONFIG_SSL_PARAM;