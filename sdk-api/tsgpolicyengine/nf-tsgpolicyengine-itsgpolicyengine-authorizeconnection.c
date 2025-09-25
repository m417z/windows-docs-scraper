HRESULT AuthorizeConnection(
  [in] GUID                        mainSessionId,
  [in] BSTR                        username,
  [in] AAAuthSchemes               authType,
  [in] BSTR                        clientMachineIP,
  [in] BSTR                        clientMachineName,
  [in] BYTE                        *sohData,
  [in] ULONG                       numSOHBytes,
  [in] BYTE                        *cookieData,
  [in] ULONG                       numCookieBytes,
  [in] HANDLE_PTR                  userToken,
  [in] ITSGAuthorizeConnectionSink *pSink
);