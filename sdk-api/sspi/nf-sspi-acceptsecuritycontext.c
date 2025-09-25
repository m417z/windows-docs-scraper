KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY AcceptSecurityContext(
  [in, optional]      PCredHandle    phCredential,
  [in, optional]      PCtxtHandle    phContext,
  [in, optional]      PSecBufferDesc pInput,
  [in]                unsigned long  fContextReq,
  [in]                unsigned long  TargetDataRep,
  [in, out, optional] PCtxtHandle    phNewContext,
  [in, out, optional] PSecBufferDesc pOutput,
  [out]               unsigned long  *pfContextAttr,
  [out, optional]     PTimeStamp     ptsExpiry
);