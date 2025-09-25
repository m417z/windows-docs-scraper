typedef struct _SSTP_CONFIG_PARAMS {
  DWORD          dwNumPorts;
  DWORD          dwPortFlags;
  BOOL           isUseHttps;
  DWORD          certAlgorithm;
  SSTP_CERT_INFO sstpCertDetails;
} SSTP_CONFIG_PARAMS, *PSSTP_CONFIG_PARAMS;