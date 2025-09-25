SECURITY_STATUS SEC_ENTRY SaslAcceptSecurityContext(
  [in]            PCredHandle    phCredential,
  [in, optional]  PCtxtHandle    phContext,
  [in]            PSecBufferDesc pInput,
  [in]            unsigned long  fContextReq,
  [in]            unsigned long  TargetDataRep,
  [out]           PCtxtHandle    phNewContext,
  [in, out]       PSecBufferDesc pOutput,
  [out]           unsigned long  *pfContextAttr,
  [out, optional] PTimeStamp     ptsExpiry
);