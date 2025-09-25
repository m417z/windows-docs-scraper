LPNSPV2LOOKUPSERVICEBEGIN Lpnspv2lookupservicebegin;

INT Lpnspv2lookupservicebegin(
  [in]  LPGUID lpProviderId,
  [in]  LPWSAQUERYSET2W lpqsRestrictions,
  [in]  DWORD dwControlFlags,
  [out] LPVOID lpvClientSessionArg,
  [out] LPHANDLE lphLookup
)
{...}