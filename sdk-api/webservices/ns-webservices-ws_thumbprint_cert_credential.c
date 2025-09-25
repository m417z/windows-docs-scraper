typedef struct _WS_THUMBPRINT_CERT_CREDENTIAL {
  WS_CERT_CREDENTIAL credential;
  ULONG              storeLocation;
  WS_STRING          storeName;
  WS_STRING          thumbprint;
} WS_THUMBPRINT_CERT_CREDENTIAL;