typedef struct IKEEXT_CERTIFICATE_AUTHENTICATION1_ {
  IKEEXT_CERT_CONFIG_TYPE inboundConfigType;
  union {
    struct {
      UINT32                   inboundRootArraySize;
      IKEEXT_CERT_ROOT_CONFIG0 *inboundRootArray;
    };
    IKEEXT_CERT_ROOT_CONFIG0 *inboundEnterpriseStoreConfig;
    IKEEXT_CERT_ROOT_CONFIG0 *inboundTrustedRootStoreConfig;
  };
  IKEEXT_CERT_CONFIG_TYPE outboundConfigType;
  union {
    struct {
      UINT32                   outboundRootArraySize;
      IKEEXT_CERT_ROOT_CONFIG0 *outboundRootArray;
    };
    IKEEXT_CERT_ROOT_CONFIG0 *outboundEnterpriseStoreConfig;
    IKEEXT_CERT_ROOT_CONFIG0 *outboundTrustedRootStoreConfig;
  };
  UINT32                  flags;
  FWP_BYTE_BLOB           localCertLocationUrl;
} IKEEXT_CERTIFICATE_AUTHENTICATION1;