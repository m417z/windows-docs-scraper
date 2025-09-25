HRESULT AuthenticateUser(
  [in] GUID                     mainSessionId,
  [in] BYTE                     *cookieData,
  [in] ULONG                    numCookieBytes,
  [in] ULONG_PTR                context,
  [in] ITSGAuthenticateUserSink *pSink
);