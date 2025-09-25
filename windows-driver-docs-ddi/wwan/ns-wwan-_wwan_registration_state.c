typedef struct _WWAN_REGISTRATION_STATE {
  ULONG               uNwError;
  WWAN_REGISTER_STATE RegisterState;
  WWAN_REGISTER_MODE  RegisterMode;
  WCHAR               ProviderId[WWAN_PROVIDERID_LEN];
  WCHAR               ProviderName[WWAN_PROVIDERNAME_LEN];
  WCHAR               RoamingText[WWAN_ROAMTEXT_LEN];
  DWORD               WwanRegFlags;
  WWAN_CELLULAR_CLASS CurrentCellularClass;
  ULONG               PreferredDataClasses;
} WWAN_REGISTRATION_STATE, *PWWAN_REGISTRATION_STATE;