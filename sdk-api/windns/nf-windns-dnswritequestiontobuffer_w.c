BOOL DnsWriteQuestionToBuffer_W(
  [in, out] PDNS_MESSAGE_BUFFER pDnsBuffer,
  [in, out] PDWORD              pdwBufferSize,
  [in]      PCWSTR              pszName,
  [in]      WORD                wType,
  [in]      WORD                Xid,
  [in]      BOOL                fRecursionDesired
);