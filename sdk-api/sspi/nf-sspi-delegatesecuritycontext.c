SECURITY_STATUS SEC_ENTRY DelegateSecurityContext(
  PCtxtHandle       phContext,
  PSECURITY_STRING  pTarget,
  SecDelegationType DelegationType,
  PTimeStamp        pExpiry,
  PSecBuffer        pPackageParameters,
  PSecBufferDesc    pOutput
);