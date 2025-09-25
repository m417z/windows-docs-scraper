LPNSPLOOKUPSERVICEBEGIN Lpnsplookupservicebegin;

INT Lpnsplookupservicebegin(
  [in]  LPGUID lpProviderId,
  [in]  LPWSAQUERYSETW lpqsRestrictions,
  [in]  LPWSASERVICECLASSINFOW lpServiceClassInfo,
  [in]  DWORD dwControlFlags,
  [out] LPHANDLE lphLookup
)
{...}