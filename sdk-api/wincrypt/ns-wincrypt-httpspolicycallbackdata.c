typedef struct _HTTPSPolicyCallbackData {
  union {
    DWORD cbStruct;
    DWORD cbSize;
  } DUMMYUNIONNAME;
  DWORD dwAuthType;
  DWORD fdwChecks;
  WCHAR *pwszServerName;
} HTTPSPolicyCallbackData, *PHTTPSPolicyCallbackData, SSL_EXTRA_CERT_CHAIN_POLICY_PARA, *PSSL_EXTRA_CERT_CHAIN_POLICY_PARA;