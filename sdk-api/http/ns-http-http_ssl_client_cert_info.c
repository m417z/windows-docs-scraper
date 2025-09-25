typedef struct _HTTP_SSL_CLIENT_CERT_INFO {
  ULONG   CertFlags;
  ULONG   CertEncodedSize;
  PUCHAR  pCertEncoded;
  HANDLE  Token;
  BOOLEAN CertDeniedByMapper;
} HTTP_SSL_CLIENT_CERT_INFO, *PHTTP_SSL_CLIENT_CERT_INFO;