SECURITY_STATUS SEC_ENTRY EncryptMessage(
  [in]      PCtxtHandle    phContext,
  [in]      unsigned long  fQOP,
  [in, out] PSecBufferDesc pMessage,
  [in]      unsigned long  MessageSeqNo
);