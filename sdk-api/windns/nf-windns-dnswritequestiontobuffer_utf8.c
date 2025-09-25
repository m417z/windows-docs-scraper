BOOL DnsWriteQuestionToBuffer_UTF8(
  [in, out] PDNS_MESSAGE_BUFFER pDnsBuffer,
  [in, out] PDWORD              pdwBufferSize,
  [in]      PCSTR               pszName,
  [in]      WORD                wType,
  [in]      WORD                Xid,
  [in]      BOOL                fRecursionDesired
);