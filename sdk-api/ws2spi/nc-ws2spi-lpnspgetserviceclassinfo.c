LPNSPGETSERVICECLASSINFO Lpnspgetserviceclassinfo;

INT Lpnspgetserviceclassinfo(
  [in]      LPGUID lpProviderId,
  [in, out] LPDWORD lpdwBufSize,
  [in, out] LPWSASERVICECLASSINFOW lpServiceClassInfo
)
{...}