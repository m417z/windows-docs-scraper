typedef struct _WWAN_PROVISIONED_CONTEXT_V2 {
  WWAN_CONTEXT                 basicInfo;
  WWAN_IP_TYPE                 IPType;
  WWAN_CONTEXT_ENABLE          Enable;
  WWAN_CONTEXT_ROAMING_CONTROL Roaming;
  WWAN_CONTEXT_MEDIA_TYPE      MediaType;
  WWAN_CONFIGURATION_SOURCE    Source;
  int                          Reserved;
  WWAN_SINGLE_NSSAI            Snssai;
} WWAN_PROVISIONED_CONTEXT_V2, *PWWAN_PROVISIONED_CONTEXT_V2;