typedef struct _DNS_SVCB_PARAM {
  WORD  wSvcParamKey;
  union {
    DNS_SVCB_PARAM_IPV4      *pIpv4Hints;
    DNS_SVCB_PARAM_IPV6      *pIpv6Hints;
    DNS_SVCB_PARAM_MANDATORY *pMandatory;
    DNS_SVCB_PARAM_ALPN      *pAlpn;
    WORD                     wPort;
    DNS_SVCB_PARAM_UNKNOWN   *pUnknown;
    PSTR                     pszDohPath;
    PVOID                    pReserved;
  };
} DNS_SVCB_PARAM;