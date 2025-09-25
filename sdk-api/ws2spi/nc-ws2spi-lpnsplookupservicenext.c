LPNSPLOOKUPSERVICENEXT Lpnsplookupservicenext;

INT Lpnsplookupservicenext(
  [in]      HANDLE hLookup,
  [in]      DWORD dwControlFlags,
  [in, out] LPDWORD lpdwBufferLength,
  [out]     LPWSAQUERYSETW lpqsResults
)
{...}