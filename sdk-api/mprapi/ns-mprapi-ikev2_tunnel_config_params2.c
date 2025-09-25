typedef struct _IKEV2_TUNNEL_CONFIG_PARAMS2 {
  DWORD                        dwIdleTimeout;
  DWORD                        dwNetworkBlackoutTime;
  DWORD                        dwSaLifeTime;
  DWORD                        dwSaDataSizeForRenegotiation;
  DWORD                        dwConfigOptions;
  DWORD                        dwTotalCertificates;
  CERT_NAME_BLOB               *certificateNames;
  CERT_NAME_BLOB               machineCertificateName;
  DWORD                        dwEncryptionType;
  PROUTER_CUSTOM_IKEv2_POLICY0 customPolicy;
} IKEV2_TUNNEL_CONFIG_PARAMS2, *PIKEV2_TUNNEL_CONFIG_PARAMS2;