typedef enum  { 
  NlsoOther,
  NlsoManual,
  NlsoWellKnown,
  NlsoDhcp,
  NlsoLinkLayerAddress,
  NlsoRandom,
  IpSuffixOriginOther             = 0,
  IpSuffixOriginManual,
  IpSuffixOriginWellKnown,
  IpSuffixOriginDhcp,
  IpSuffixOriginLinkLayerAddress,
  IpSuffixOriginRandom,
  IpSuffixOriginUnchanged         = 1 << 4
} NL_SUFFIX_ORIGIN;