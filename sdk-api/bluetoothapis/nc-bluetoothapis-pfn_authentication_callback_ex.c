PFN_AUTHENTICATION_CALLBACK_EX PfnAuthenticationCallbackEx;

BOOL PfnAuthenticationCallbackEx(
  [in, optional] LPVOID pvParam,
  [in]           PBLUETOOTH_AUTHENTICATION_CALLBACK_PARAMS pAuthCallbackParams
)
{...}