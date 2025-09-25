LPNSPV2LOOKUPSERVICENEXTEX Lpnspv2lookupservicenextex;

VOID Lpnspv2lookupservicenextex(
  [in]      HANDLE hAsyncCall,
  [in]      HANDLE hLookup,
  [in]      DWORD dwControlFlags,
  [in, out] LPDWORD lpdwBufferLength,
  [out]     LPWSAQUERYSET2W lpqsResults
)
{...}