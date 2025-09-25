KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY VerifySignature(
  [in]  PCtxtHandle    phContext,
  [in]  PSecBufferDesc pMessage,
  [in]  unsigned long  MessageSeqNo,
  [out] unsigned long  *pfQOP
);