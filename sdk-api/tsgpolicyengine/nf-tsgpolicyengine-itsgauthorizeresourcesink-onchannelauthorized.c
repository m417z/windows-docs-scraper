HRESULT OnChannelAuthorized(
  [in] HRESULT hrIn,
  [in] GUID    mainSessionId,
  [in] int     subSessionId,
  [in] BSTR    *allowedResourceNames,
  [in] ULONG   numAllowedResourceNames,
  [in] BSTR    *failedResourceNames,
  [in] ULONG   numFailedResourceNames
);