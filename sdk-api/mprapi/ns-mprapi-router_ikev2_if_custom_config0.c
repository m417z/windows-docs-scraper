typedef struct _ROUTER_IKEv2_IF_CUSTOM_CONFIG0 {
  DWORD                       dwSaLifeTime;
  DWORD                       dwSaDataSize;
  CERT_NAME_BLOB              certificateName;
  ROUTER_CUSTOM_IKEv2_POLICY0 *customPolicy;
} ROUTER_IKEv2_IF_CUSTOM_CONFIG0, *PROUTER_IKEv2_IF_CUSTOM_CONFIG0;