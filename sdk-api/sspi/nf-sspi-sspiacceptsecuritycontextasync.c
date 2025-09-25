SECURITY_STATUS SspiAcceptSecurityContextAsync(
  SspiAsyncContext *AsyncContext,
  PCredHandle      phCredential,
  PCtxtHandle      phContext,
  PSecBufferDesc   pInput,
  unsigned long    fContextReq,
  unsigned long    TargetDataRep,
  PCtxtHandle      phNewContext,
  PSecBufferDesc   pOutput,
  unsigned long    *pfContextAttr,
  PTimeStamp       ptsExpiry
);