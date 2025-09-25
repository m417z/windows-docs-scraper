typedef struct _HTTP_SSL_INFO {
  USHORT                     ServerCertKeySize;
  USHORT                     ConnectionKeySize;
  ULONG                      ServerCertIssuerSize;
  ULONG                      ServerCertSubjectSize;
  PCSTR                      pServerCertIssuer;
  PCSTR                      pServerCertSubject;
  PHTTP_SSL_CLIENT_CERT_INFO pClientCertInfo;
  ULONG                      SslClientCertNegotiated;
} HTTP_SSL_INFO, *PHTTP_SSL_INFO;