SECURITY_STATUS SEC_ENTRY InitializeSecurityContextA(
  [in, optional]      PCredHandle    phCredential,
  [in, optional]      PCtxtHandle    phContext,
                      SEC_CHAR       *pszTargetName,
  [in]                unsigned long  fContextReq,
  [in]                unsigned long  Reserved1,
  [in]                unsigned long  TargetDataRep,
  [in, optional]      PSecBufferDesc pInput,
  [in]                unsigned long  Reserved2,
  [in, out, optional] PCtxtHandle    phNewContext,
  [in, out, optional] PSecBufferDesc pOutput,
  [out]               unsigned long  *pfContextAttr,
  [out, optional]     PTimeStamp     ptsExpiry
);