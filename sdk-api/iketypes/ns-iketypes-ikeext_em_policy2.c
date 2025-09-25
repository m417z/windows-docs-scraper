typedef struct IKEEXT_EM_POLICY2_ {
  UINT32                                   numAuthenticationMethods;
  IKEEXT_AUTHENTICATION_METHOD2            *authenticationMethods;
  IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE initiatorImpersonationType;
} IKEEXT_EM_POLICY2;