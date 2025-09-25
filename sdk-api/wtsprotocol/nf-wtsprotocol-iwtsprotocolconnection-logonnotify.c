HRESULT LogonNotify(
  [in] HANDLE_PTR     hClientToken,
  [in] WCHAR          *wszUserName,
  [in] WCHAR          *wszDomainName,
  [in] WTS_SESSION_ID *SessionId
);