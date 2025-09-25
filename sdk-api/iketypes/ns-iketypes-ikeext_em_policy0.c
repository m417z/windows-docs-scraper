typedef struct IKEEXT_EM_POLICY0_ {
  UINT32                                   numAuthenticationMethods;
  IKEEXT_AUTHENTICATION_METHOD0            *authenticationMethods;
  IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE initiatorImpersonationType;
} IKEEXT_EM_POLICY0;