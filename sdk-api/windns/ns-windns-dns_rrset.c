typedef struct _DnsRRSet {
  PDNS_RECORD pFirstRR;
  PDNS_RECORD pLastRR;
} DNS_RRSET, *PDNS_RRSET;