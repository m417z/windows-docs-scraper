typedef struct _WWAN_REGISTRATION_PARAMS_INFO {
  WWAN_MICO_MODE                MicoMode;
  WWAN_DRX_PARAMS               DRXParam;
  WWAN_LADN_IND_REQUEST         LADNInfo;
  WWAN_DEFAULT_PDU_SESSION_HINT DefaultPDUSessionHint;
  UINT32                        ReRegisterIfNeeded;
  GUID                          OSId;
  WWAN_LIST_HEADER              PreConfiguredNSSAIListHeader;
} WWAN_REGISTRATION_PARAMS_INFO, *PWWAN_REGISTRATION_PARAMS_INFO;