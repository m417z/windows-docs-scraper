typedef struct _WWAN_SET_REGISTER_STATE {
  WCHAR                ProviderId[WWAN_PROVIDERID_LEN];
  WWAN_REGISTER_ACTION RegisterAction;
  ULONG                WwanDataClass;
} WWAN_SET_REGISTER_STATE, *PWWAN_SET_REGISTER_STATE;