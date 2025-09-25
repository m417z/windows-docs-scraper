typedef struct IKEEXT_CERTIFICATE_AUTHENTICATION2_ {
  IKEEXT_CERT_CONFIG_TYPE inboundConfigType;
  union {
    struct {
      UINT32                       inboundRootArraySize;
      IKEEXT_CERTIFICATE_CRITERIA0 *inboundRootCriteria;
    };
    struct {
      UINT32                       inboundEnterpriseStoreArraySize;
      IKEEXT_CERTIFICATE_CRITERIA0 *inboundEnterpriseStoreCriteria;
    };
    struct {
      UINT32                       inboundRootStoreArraySize;
      IKEEXT_CERTIFICATE_CRITERIA0 *inboundTrustedRootStoreCriteria;
    };
  };
  IKEEXT_CERT_CONFIG_TYPE outboundConfigType;
  union {
    struct {
      UINT32                       outboundRootArraySize;
      IKEEXT_CERTIFICATE_CRITERIA0 *outboundRootCriteria;
    };
    struct {
      UINT32                       outboundEnterpriseStoreArraySize;
      IKEEXT_CERTIFICATE_CRITERIA0 *outboundEnterpriseStoreCriteria;
    };
    struct {
      UINT32                       outboundRootStoreArraySize;
      IKEEXT_CERTIFICATE_CRITERIA0 *outboundTrustedRootStoreCriteria;
    };
  };
  UINT32                  flags;
  FWP_BYTE_BLOB           localCertLocationUrl;
} IKEEXT_CERTIFICATE_AUTHENTICATION2;