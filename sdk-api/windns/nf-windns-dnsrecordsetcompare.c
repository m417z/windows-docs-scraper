BOOL DnsRecordSetCompare(
  [in, out]       PDNS_RECORD pRR1,
  [in, out]       PDNS_RECORD pRR2,
  [out, optional] PDNS_RECORD *ppDiff1,
  [out, optional] PDNS_RECORD *ppDiff2
);