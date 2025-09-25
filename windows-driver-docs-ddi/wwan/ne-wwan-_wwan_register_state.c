typedef enum _WWAN_REGISTER_STATE {
  WwanRegisterStateUnknown,
  WwanRegisterStateDeregistered,
  WwanRegisterStateSearching,
  WwanRegisterStateHome,
  WwanRegisterStateRoaming,
  WwanRegisterStatePartner,
  WwanRegisterStateDenied,
  WwanRegisterStateMax
} WWAN_REGISTER_STATE, *PWWAN_REGISTER_STATE;