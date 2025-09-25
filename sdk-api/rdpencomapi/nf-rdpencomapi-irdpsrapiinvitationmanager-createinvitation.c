HRESULT CreateInvitation(
  [in]  BSTR                bstrAuthString,
  [in]  BSTR                bstrGroupName,
  [in]  BSTR                bstrPassword,
  [in]  long                AttendeeLimit,
  [out] IRDPSRAPIInvitation **ppInvitation
);