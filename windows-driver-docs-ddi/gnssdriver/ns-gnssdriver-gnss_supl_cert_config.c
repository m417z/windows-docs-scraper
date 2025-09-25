typedef struct {
  ULONG                 Size;
  ULONG                 Version;
  GNSS_SUPL_CERT_ACTION CertAction;
  CHAR                  SuplCertName[MAX_PATH];
  ULONG                 CertSize;
  BYTE                  Unused[512];
  BYTE                  CertData[ANYSIZE_ARRAY];
} GNSS_SUPL_CERT_CONFIG, *PGNSS_SUPL_CERT_CONFIG;