typedef struct _CERT_OR_CRL_BLOB {
  DWORD dwChoice;
  DWORD cbEncoded;
  BYTE  *pbEncoded;
} CERT_OR_CRL_BLOB, *PCERT_OR_CRL_BLOB;