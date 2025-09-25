typedef enum _DNS_SVCB_PARAM_TYPE {
  DnsSvcbParamMandatory = 0,
  DnsSvcbParamAlpn = 1,
  DnsSvcbParamNoDefaultAlpn = 2,
  DnsSvcbParamPort = 3,
  DnsSvcbParamIpv4Hint = 4,
  DnsSvcbParamEch = 5,
  DnsSvcbParamIpv6Hint = 6,
  DnsSvcbParamDohPath = 7,
  DnsSvcbParamDohPathOpenDns = 65432
} DNS_SVCB_PARAM_TYPE;