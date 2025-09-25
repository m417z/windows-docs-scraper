typedef struct IKEEXT_POLICY2_ {
  UINT32                                   softExpirationTime;
  UINT32                                   numAuthenticationMethods;
  IKEEXT_AUTHENTICATION_METHOD2            *authenticationMethods;
  IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE initiatorImpersonationType;
  UINT32                                   numIkeProposals;
  IKEEXT_PROPOSAL0                         *ikeProposals;
  UINT32                                   flags;
  UINT32                                   maxDynamicFilters;
  UINT32                                   retransmitDurationSecs;
} IKEEXT_POLICY2;