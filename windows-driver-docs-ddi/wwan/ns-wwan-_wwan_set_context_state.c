typedef struct _WWAN_SET_CONTEXT_STATE {
  ULONG                     ConnectionId;
  WWAN_ACTIVATION_COMMAND   ActivationCommand;
  WCHAR                     AccessString[WWAN_ACCESSSTRING_LEN];
  WCHAR                     UserName[WWAN_USERNAME_LEN];
  WCHAR                     Password[WWAN_PASSWORD_LEN];
  WWAN_COMPRESSION          Compression;
  WWAN_AUTH_PROTOCOL        AuthType;
  WWAN_IP_TYPE              IPType;
  WWAN_PSMEDIA_PREFERENCE   MediaPreference;
  WWAN_CONFIGURATION_SOURCE ConnectionMediaSource;
  WWAN_ACTIVATION_OPTION    ActivationOption;
  WWAN_SINGLE_NSSAI         Snssai;
  WWAN_OFFSET_SIZE_ELEMENT  TrafficParameters;
} WWAN_SET_CONTEXT_STATE, *PWWAN_SET_CONTEXT_STATE;