typedef struct _CRYPT_REGISTER_ACTIONID {
  DWORD                 cbStruct;
  CRYPT_TRUST_REG_ENTRY sInitProvider;
  CRYPT_TRUST_REG_ENTRY sObjectProvider;
  CRYPT_TRUST_REG_ENTRY sSignatureProvider;
  CRYPT_TRUST_REG_ENTRY sCertificateProvider;
  CRYPT_TRUST_REG_ENTRY sCertificatePolicyProvider;
  CRYPT_TRUST_REG_ENTRY sFinalPolicyProvider;
  CRYPT_TRUST_REG_ENTRY sTestPolicyProvider;
  CRYPT_TRUST_REG_ENTRY sCleanupProvider;
} CRYPT_REGISTER_ACTIONID, *PCRYPT_REGISTER_ACTIONID;