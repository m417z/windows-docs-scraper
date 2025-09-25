HRESULT AuthorizeResource(
  [in] GUID                      mainSessionId,
  [in] int                       subSessionId,
  [in] BSTR                      username,
  [in] BSTR                      *resourceNames,
  [in] ULONG                     numResources,
  [in] BSTR                      *alternateResourceNames,
  [in] ULONG                     numAlternateResourceName,
  [in] ULONG                     portNumber,
  [in] BSTR                      operation,
  [in] BYTE                      *cookie,
  [in] ULONG                     numBytesInCookie,
  [in] ITSGAuthorizeResourceSink *pSink
);