typedef struct IKEEXT_POLICY0_ {
  UINT32                                   softExpirationTime;
  UINT32                                   numAuthenticationMethods;
  IKEEXT_AUTHENTICATION_METHOD0            *authenticationMethods;
  IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE initiatorImpersonationType;
  UINT32                                   numIkeProposals;
  IKEEXT_PROPOSAL0                         *ikeProposals;
  UINT32                                   flags;
  UINT32                                   maxDynamicFilters;
} IKEEXT_POLICY0;