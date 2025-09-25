typedef struct IKEEXT_EM_POLICY1_ {
  UINT32                                   numAuthenticationMethods;
  IKEEXT_AUTHENTICATION_METHOD1            *authenticationMethods;
  IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE initiatorImpersonationType;
} IKEEXT_EM_POLICY1;