LPNSPV2SETSERVICEEX Lpnspv2setserviceex;

VOID Lpnspv2setserviceex(
  [in] HANDLE hAsyncCall,
  [in] LPGUID lpProviderId,
  [in] LPWSAQUERYSET2W lpqsRegInfo,
  [in] WSAESETSERVICEOP essOperation,
  [in] DWORD dwControlFlags,
  [in] LPVOID lpvClientSessionArg
)
{...}