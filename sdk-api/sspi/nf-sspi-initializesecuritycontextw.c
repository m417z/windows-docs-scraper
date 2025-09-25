KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY InitializeSecurityContextW(
  [in, optional]      PCredHandle      phCredential,
  [in, optional]      PCtxtHandle      phContext,
  [in, optional]      PSECURITY_STRING pTargetName,
  [in]                unsigned long    fContextReq,
  [in]                unsigned long    Reserved1,
  [in]                unsigned long    TargetDataRep,
  [in, optional]      PSecBufferDesc   pInput,
  [in]                unsigned long    Reserved2,
  [in, out, optional] PCtxtHandle      phNewContext,
  [in, out, optional] PSecBufferDesc   pOutput,
  [out]               unsigned long    *pfContextAttr,
  [out, optional]     PTimeStamp       ptsExpiry
);