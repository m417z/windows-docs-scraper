PFNDAVAUTHCALLBACK Pfndavauthcallback;

DWORD Pfndavauthcallback(
  [in]      LPWSTR lpwzServerName,
  [in]      LPWSTR lpwzRemoteName,
  [in]      DWORD dwAuthScheme,
  [in]      DWORD dwFlags,
  [in, out] PDAV_CALLBACK_CRED pCallbackCred,
  [in, out] AUTHNEXTSTEP *NextStep,
  [out]     PFNDAVAUTHCALLBACK_FREECRED *pFreeCred
)
{...}