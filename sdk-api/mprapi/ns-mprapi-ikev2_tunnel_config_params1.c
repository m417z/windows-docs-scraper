typedef struct _IKEV2_TUNNEL_CONFIG_PARAMS1 {
  DWORD          dwIdleTimeout;
  DWORD          dwNetworkBlackoutTime;
  DWORD          dwSaLifeTime;
  DWORD          dwSaDataSizeForRenegotiation;
  DWORD          dwConfigOptions;
  DWORD          dwTotalCertificates;
  CERT_NAME_BLOB *certificateNames;
} IKEV2_TUNNEL_CONFIG_PARAMS1, *PIKEV2_TUNNEL_CONFIG_PARAMS1;