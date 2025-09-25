SECURITY_STATUS SspiInitializeSecurityContextAsyncA(
  SspiAsyncContext *AsyncContext,
  PCredHandle      phCredential,
  PCtxtHandle      phContext,
  LPSTR            pszTargetName,
  unsigned long    fContextReq,
  unsigned long    Reserved1,
  unsigned long    TargetDataRep,
  PSecBufferDesc   pInput,
  unsigned long    Reserved2,
  PCtxtHandle      phNewContext,
  PSecBufferDesc   pOutput,
  unsigned long    *pfContextAttr,
  PTimeStamp       ptsExpiry
);