SECURITY_STATUS SEC_ENTRY DecryptMessage(
  [in]      PCtxtHandle    phContext,
  [in, out] PSecBufferDesc pMessage,
  [in]      unsigned long  MessageSeqNo,
  [out]     unsigned long  *pfQOP
);