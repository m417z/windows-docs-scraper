LPNSPSETSERVICE Lpnspsetservice;

INT Lpnspsetservice(
  [in] LPGUID lpProviderId,
  [in] LPWSASERVICECLASSINFOW lpServiceClassInfo,
  [in] LPWSAQUERYSETW lpqsRegInfo,
  [in] WSAESETSERVICEOP essOperation,
  [in] DWORD dwControlFlags
)
{...}