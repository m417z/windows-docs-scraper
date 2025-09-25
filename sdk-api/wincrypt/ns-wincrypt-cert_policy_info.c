typedef struct _CERT_POLICY_INFO {
  LPSTR                      pszPolicyIdentifier;
  DWORD                      cPolicyQualifier;
  CERT_POLICY_QUALIFIER_INFO *rgPolicyQualifier;
} CERT_POLICY_INFO, *PCERT_POLICY_INFO;