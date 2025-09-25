typedef struct _WS_CERT_ENDPOINT_IDENTITY {
  WS_ENDPOINT_IDENTITY identity;
  WS_BYTES             rawCertificateData;
} WS_CERT_ENDPOINT_IDENTITY;