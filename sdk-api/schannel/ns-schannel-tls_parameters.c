typedef struct _TLS_PARAMETERS {
  DWORD            cAlpnIds;
  PUNICODE_STRING  rgstrAlpnIds;
  DWORD            grbitDisabledProtocols;
  DWORD            cDisabledCrypto;
  PCRYPTO_SETTINGS pDisabledCrypto;
  DWORD            dwFlags;
} TLS_PARAMETERS, *PTLS_PARAMETERS;