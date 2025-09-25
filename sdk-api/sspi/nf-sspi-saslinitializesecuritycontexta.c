SECURITY_STATUS SEC_ENTRY SaslInitializeSecurityContextA(
  [in]            PCredHandle    phCredential,
  [in]            PCtxtHandle    phContext,
  [in]            LPSTR          pszTargetName,
  [in]            unsigned long  fContextReq,
  [in]            unsigned long  Reserved1,
  [in]            unsigned long  TargetDataRep,
  [in]            PSecBufferDesc pInput,
  [in]            unsigned long  Reserved2,
  [out]           PCtxtHandle    phNewContext,
  [in, out]       PSecBufferDesc pOutput,
  [out]           unsigned long  *pfContextAttr,
  [out, optional] PTimeStamp     ptsExpiry
);