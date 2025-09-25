BOOL CryptUIWizDigitalSign(
  [in]            DWORD                              dwFlags,
  [in, optional]  HWND                               hwndParent,
  [in, optional]  LPCWSTR                            pwszWizardTitle,
  [in]            PCCRYPTUI_WIZ_DIGITAL_SIGN_INFO    pDigitalSignInfo,
  [out, optional] PCCRYPTUI_WIZ_DIGITAL_SIGN_CONTEXT *ppSignContext
);