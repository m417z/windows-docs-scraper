KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY MakeSignature(
  [in]      PCtxtHandle    phContext,
  [in]      unsigned long  fQOP,
  [in, out] PSecBufferDesc pMessage,
  [in]      unsigned long  MessageSeqNo
);