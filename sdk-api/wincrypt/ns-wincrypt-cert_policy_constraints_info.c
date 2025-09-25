typedef struct _CERT_POLICY_CONSTRAINTS_INFO {
  BOOL  fRequireExplicitPolicy;
  DWORD dwRequireExplicitPolicySkipCerts;
  BOOL  fInhibitPolicyMapping;
  DWORD dwInhibitPolicyMappingSkipCerts;
} CERT_POLICY_CONSTRAINTS_INFO, *PCERT_POLICY_CONSTRAINTS_INFO;