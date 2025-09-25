typedef struct _SEC_CERTIFICATE_REQUEST_CONTEXT {
  unsigned char cbCertificateRequestContext;
  unsigned char rgCertificateRequestContext[ANYSIZE_ARRAY];
} SEC_CERTIFICATE_REQUEST_CONTEXT, *PSEC_CERTIFICATE_REQUEST_CONTEXT;