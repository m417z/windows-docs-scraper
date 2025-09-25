HRESULT LogonNotify(
  [in]      HANDLE_PTR                hClientToken,
  [in]      WCHAR                     *wszUserName,
  [in]      WCHAR                     *wszDomainName,
  [in]      WRDS_SESSION_ID           *SessionId,
  [in, out] PWRDS_CONNECTION_SETTINGS pWRdsConnectionSettings
);