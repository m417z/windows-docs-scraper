WINHTTPAPI BOOL WinHttpSetTimeouts(
  [in] HINTERNET hInternet,
  [in] int       nResolveTimeout,
  [in] int       nConnectTimeout,
  [in] int       nSendTimeout,
  [in] int       nReceiveTimeout
);